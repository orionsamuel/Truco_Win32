#pragma once

#include "card.h"
#include <memory>
#include <vector>

class deck {
public:
    deck() = default;

    std::vector<std::shared_ptr<card>> baseCards;
};
