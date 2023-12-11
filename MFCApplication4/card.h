#pragma once
#include <string>

enum class Suit { SPADES, HEARTS, CLUBS, DIAMONDS };
enum class Value { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, JACK, QUEEN, KING };

class Card {
public:
    Card() = default;
    void setSuit(Suit s);
    Suit getSuit() const;
    void setValue(Value v);
    Value getValue() const;
    void displayCard() const;

private:
    Suit suit;
    Value value;
};
