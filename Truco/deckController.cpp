#include<iostream>

#include "deckController.h"

void deckController::addCard(cardController card)
{
	deckCards.baseCards.push_back(std::make_shared<card>(card.getCard()));
}

cardController deckController::popCard()
{
	if (!deckCards.baseCards.empty())
	{
		std::shared_ptr<card> card = deckCards.baseCards.back();
		deckCards.baseCards.pop_back();

		cardController cc;
		cc.createCard(card->suit, card->value);

		return cc;
	}
}