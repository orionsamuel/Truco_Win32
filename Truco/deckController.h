#pragma once
#include<memory>
#include<iostream>

#include "cardController.h"
#include "deck.h"
#include "deckView.h"

class deckController {
public:
	deckController() = default;
	deckController(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);

	void displayDeck() const;
	bool canAddCard(cardController newCard);
	void addCard(cardController newCard);
	cardController popCard();

	void changeCardSelection(int cardId);
	void enableToSelectCard() const;

private:
	int _positionX;
	int _positionY;
	CFrameWnd* _parentWindow;
	UINT _deckId;

	deck _deckCards;
	deckView* _deckView;
};