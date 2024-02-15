#include "deckController.h"
#include "pch.h"

deckController::deckController(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_positionX = positionX;
	_positionY = positionY;
	_parentWindow = pParentWnd;
	_deckId = nID;

	_deckView = new deckView(positionX, positionY, pParentWnd, nID);
}

void deckController::displayDeck()
{
	auto list = _deckView->displayDeck(_deckCards);
	for (auto& card : list) {
		_cardList.push_back(card);
	}
}

bool deckController::canAddCard(cardController newCard)
{
	if (!_deckCards.baseCards.empty())
	{
		for (auto& card : _deckCards.baseCards) {
			if (card->getSuit() == newCard.getSuit() && card->getValue() == newCard.getValue())
			{
				return false;
			}
		}
	}

	return true;
}

void deckController::addCard(cardController newCard)
{
	try {
		_deckCards.baseCards.push_back(std::make_shared<card>(newCard.getCard()));
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Error adding card to deck: " << e.what() << std::endl;
	}
}

cardController deckController::removeCard(WPARAM wParam) {
	try {
		if (!_cardList.empty()) {
			for (auto& card : _cardList) {
				if (card->cardId == wParam) {
					cardController newCard(_positionX, _positionY, _parentWindow, card->cardId);

					remove(_cardList.begin(), _cardList.end(), card);

					return newCard;
				}
			}
		}
		else {
			throw std::out_of_range("Deck is empty");
		}
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error to remove card from deck: " << e.what() << std::endl;
	}
}

cardController deckController::popCard()
{
	try {
		if (!_deckCards.baseCards.empty()) {
			std::shared_ptr<card> card = _deckCards.baseCards.back();
			_deckCards.baseCards.pop_back();

			cardController cc(_positionX, _positionY, _parentWindow, _deckId);
			cc.createCard(card->getSuit(), card->getValue());

			return cc;
		}
		else {
			throw std::out_of_range("Deck is empty");
		}
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error popping card from deck: " << e.what() << std::endl;
	}
}

void deckController::popCard(cardController currCard)
{
	try {
		if (!_deckCards.baseCards.empty()) {
			for (auto& card : _deckCards.baseCards) {
				if (card->getSuit() == currCard.getSuit() && card->getValue() == currCard.getValue()) {
					remove(_deckCards.baseCards.begin(), _deckCards.baseCards.end(), card);
					break;
				}
			}
		}
		else {
			throw std::out_of_range("Deck is empty");
		}
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error popping card from deck: " << e.what() << std::endl;
	}
}

void deckController::removeSelectedCards() const {
	_deckView->removeSelectedCards();
}

void deckController::changeCardSelection(int cardId)
{
	_deckView->changeCardSelection(cardId);
}

void deckController::enableToSelectCard() const
{
	_deckView->enableToSelectCard();
}

void deckController::clear()
{
	_deckCards.baseCards.clear();
	_cardList.clear();

	_deckView->~deckView();
}
