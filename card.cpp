#include "card.hpp"
#include <iostream>

Card::Card() {}

void Card::setSuit(Suit s) {
    suit = s;
}

Suit Card::getSuit() const {
    return suit;
}

void Card::setValue(Value v) {
    value = v;
}

Value Card::getValue() const {
    return value;

}

void Card::displayCard() {
    //TODO: modify when uses UI
    std::string suitStr;
    std::string valueStr;

    switch (suit) {
        case Suit::SPADES:
            suitStr = "Spades";
            break;
        case Suit::HEARTS:
            suitStr = "Hearts";
            break;
        case Suit::CLUBS:
            suitStr = "Clubs";
            break;
        case Suit::DIAMONDS:
            suitStr = "Diamonds";
            break;
    }

    switch (value) {
        case Value::ACE:
            valueStr = "Ace";
            break;
        case Value::TWO:
            valueStr = "Two";
            break;
        case Value::THREE:
            valueStr = "Three";
            break;
        case Value::FOUR:
            valueStr = "Four";
            break;
        case Value::FIVE:
            valueStr = "Five";
            break;
        case Value::SIX:
            valueStr = "Six";
            break;
        case Value::SEVEN:
            valueStr = "Seven";
            break;
        case Value::JACK:
            valueStr = "Jack";
            break;
        case Value::QUEEN:
            valueStr = "Queen";
            break;
        case Value::KING:
            valueStr = "King";
            break;
    }

    std::cout << valueStr << " of " << suitStr << std::endl;
}
