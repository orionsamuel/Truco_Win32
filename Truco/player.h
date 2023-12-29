#pragma once
#include "card.h"
#include "deck.h"
#include <vector>
#include <memory>
#include <string>

class player {
public:
    player() = default;

    std::string name;
    deck cardList;
};
