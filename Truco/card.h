#pragma once
#include <string>
#include<iostream>
#define stringify( name ) #name

#include "enums.h"
#include "converters.h"

class card {
public:
    card() = default;
    void setSuit(Suit cardSuit);
    Suit getSuit() const;
    void setValue(Value cardValue);
    Value getValue() const;

    std::string getCardDescription() const;

private:
    Suit _suit;
    Value _value;

};
