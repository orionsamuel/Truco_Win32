#pragma once
#include <vector>

#include "cardController.h"
#include "deck.h"

class deckView
{
public:
	deckView() = default;
	deckView(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);
	void displayDeck(deck deckCards);
	void changeCardSelection(int cardId);
	void enableToSelectCard() const;

private:
	int _positionX;
	int _positionY;
	CFrameWnd* _parentWindow;
	UINT _deckId;

	std::vector<std::shared_ptr<cardController>>_cardList;
};

