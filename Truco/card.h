#pragma once
#include <string>

enum class Suit { SPADES, HEARTS, CLUBS, DIAMONDS };
enum class Value { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, JACK, QUEEN, KING };

class card {
public:
    card() = default;
    void setSuit(Suit s);
    Suit getSuit() const;
    void setValue(Value v);
    Value getValue() const;
    void displaycard() const;

private:
    Suit suit;
    Value value;
};
