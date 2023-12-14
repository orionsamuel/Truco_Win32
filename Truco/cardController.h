#pragma once
#include "card.h"
#include "cardView.h"

class cardController
{
	card c;
	cardView cv;

public:
	cardController() = default;
	cardController(card& c, cardView& cv);
	void displayCard();
};

