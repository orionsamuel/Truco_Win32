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
	cardController(card& c, cardView& cv);
	void createCard(Suit s, Value v);
	void displayCard();
	card getCard();
	Suit getSuit();
	Value getValue();
	void generateCard();

private:
	card c;
	cardView cv;
	std::mt19937 randomEngine;

	int getRandomNumber(int min, int max);
};

