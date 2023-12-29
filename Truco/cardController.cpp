#include "cardController.h"
#include "pch.h"


cardController::cardController(card& c, cardView& cv) : c(c), cv(cv) {}

void cardController::createCard(Suit s, Value v)
{
	c.suit = s;
	c.suit = v;
}

void cardController::displayCard()
{
	cv.displayCard(c);
}

card cardController::getCard()
{
	return c;
}

Suit cardController::getSuit()
{
	std::uniform_int_distribution<int> distribution(0, static_cast<int>(Suit::DIAMONDS));
	return static_cast<Suit>(distribution(randomEngine));
}

Value cardController::getValue()
{
	std::uniform_int_distribution<int> distribution(0, static_cast<int>(Value::KING));
	return static_cast<Value>(distribution(randomEngine));
}