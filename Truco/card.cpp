#include "pch.h"
#include "card.h"

void card::setSuit(Suit cardSuit)
{
	_suit = cardSuit;
}

Suit card::getSuit() const
{
	return _suit;
}

void card::setValue(Value cardValue)
{
	_value = cardValue;
}

Value card::getValue() const
{
	return _value;
}


std::string card::getCardDescription() const
{
	return stringify(getSuit());
}
