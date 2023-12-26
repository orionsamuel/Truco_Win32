#pragma once

#include "card.h"
#include <memory>
#include <vector>

class deck {
public:
    deck();
    void displaydeck() const;
    std::shared_ptr<card> dealcard();
    void shuffle();

private:
    std::vector<std::shared_ptr<card>> cards;
};
