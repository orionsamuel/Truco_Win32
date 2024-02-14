#pragma once
#include <ctime>
#include <random>
#include <string>

#include "card.h"
#include "cardView.h"
#include "enums.h"

class cardController
{
public:
	UINT cardId;

	cardController() = default;
	cardController(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);
	cardController(int positionX, int positionY, int selectedPosX, int selectedPosY, CFrameWnd* pParentWnd, UINT nID);

	void createCard(Suit suit, Value value);
	void displayCard(bool isEnabled = true);
	card getCard();
	Suit getSuit();
	Value getValue();
	void generateCard();
	void enableCard(bool isEnabled = true) const;
	bool changeCardSelection();

private:
	card _card;
	cardView* _cardView;
	std::mt19937 randomEngine;

	bool _isSelected;
};

