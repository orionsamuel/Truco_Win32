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
	std::string suitStr = converters::convertSuitToString(getSuit());
	std::string valueStr = converters::convertValueToString(getValue());

	std::string cardName = valueStr + "\r\nof\r\n" + suitStr;
	return cardName;
}
