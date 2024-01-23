#pragma once
#include<memory>

#include "card.h"
#include "cardController.h"
#include "deck.h"

class deckController {
public:
	deckController() = default;

	void addCard(cardController newCard);
	cardController popCard();

private:
	deck deckCards;
};