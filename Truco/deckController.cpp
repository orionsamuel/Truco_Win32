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

void deckController::displayDeck() const
{
	_deckView->displayDeck(_deckCards);
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
		return cardController();
	}
}

void deckController::changeCardSelection(int cardId)
{
	_deckView->changeCardSelection(cardId);
}

void deckController::enableToSelectCard() const
{
	_deckView->enableToSelectCard();
}
