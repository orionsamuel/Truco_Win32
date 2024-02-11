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
	cardController() = default;
	cardController(bool isVertical, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);

	void createCard(Suit suit, Value value);
	void displayCard();
	card getCard();
	Suit getSuit();
	Value getValue();
	void generateCard();

private:
	card _card;
	cardView* _cardView;
	std::mt19937 randomEngine;

	int getRandomNumber(int min, int max);
};

