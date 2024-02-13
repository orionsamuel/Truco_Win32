#include "pch.h"
#include "deckView.h"

deckView::deckView(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_positionX = positionX;
	_positionY = positionY;
	_parentWindow = pParentWnd;
	_deckId = nID;
}

void deckView::displayDeck(deck deckCards) const
{
	try {
		if (!deckCards.baseCards.empty()) {

			int posX = _positionX;
			int cardId = _deckId + 1;
			for (auto& card : deckCards.baseCards) {
				cardController cc(posX, _positionY, _parentWindow, cardId);
				cc.createCard(card->getSuit(), card->getValue());

				cc.displayCard();

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
