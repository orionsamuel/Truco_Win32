#pragma once
#include <string>

#include "enums.h"

class converters
{
public:

	static std::string convertSuitToString(Suit suit) {
		switch (suit) {
		case Suit::SPADES:
			return "Spades";
		case Suit::HEARTS:
			return "Hearts";
		case Suit::CLUBS:
			return "Clubs";
		case Suit::DIAMONDS:
			return "Diamonds";
		}
	}

	static std::string convertValueToString(Value value) {
		switch (value) {
		case Value::ACE:
			return "Ace";
		case Value::TWO:
			return "Two";
		case Value::THREE:
			return "Three";
		case Value::FOUR:
			return "Four";
		case Value::FIVE:
			return "Five";
		case Value::SIX:
			return "Six";
		case Value::SEVEN:
			return "Seven";
		case Value::JACK:
			return "Jack";
		case Value::QUEEN:
			return "Queen";
		case Value::KING:
			return "King";
		}
	}

	static std::string convertPlayerTypeToString(PlayerType playerType) {
		switch (playerType)
		{
		case PlayerType::CPU:
			return "CPU";
		case PlayerType::PLAYER:
			return "Player";
		}
	}

};

