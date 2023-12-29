#pragma once
#include "enums.h"

class card {
public:
    card() = default;
    card(Suit s, Value v) : suit(s), value(v) {}

    Suit suit;
    Value value;
};
