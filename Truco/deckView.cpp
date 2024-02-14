#include "deckView.h"
#include "pch.h"

deckView::deckView(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_positionX = positionX;
	_positionY = positionY;
	_parentWindow = pParentWnd;
	_deckId = nID;
}

void deckView::displayDeck(deck deckCards)
{
	try {
		if (!deckCards.baseCards.empty()) {

			int posX = _positionX;
			int selectedPosX = posX + 180;
			int selectedPosY = _positionY - 90;
			int cardId = _deckId + 1;

			for (auto& card : deckCards.baseCards) {

				cardController cc(posX, _positionY, selectedPosX, selectedPosY, _parentWindow, cardId);
				cc.createCard(card->getSuit(), card->getValue());

				cc.displayCard(false);

				_cardList.push_back(std::make_shared<cardController>(cc));

				posX += 95;
				cardId++;
			}
		}
		else {
			throw std::out_of_range("Deck is empty");
		}
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error to display deck: " << e.what() << std::endl;
	}
}

void deckView::changeCardSelection(int cardId)
{
	bool isSelected = false;
	for (auto& card : _cardList) {
		if (card->cardId == cardId) {
			isSelected = card->changeCardSelection();
			break;
		}
	}

	for (auto& card : _cardList) {
		card->enableCard(!isSelected);
	}
}

void deckView::enableToSelectCard() const {
	for (auto& card : _cardList) {
		card->enableCard(true);
	}
}
