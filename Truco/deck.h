#pragma once

#include "card.h"
#include <memory>
#include <vector>

class deck {
public:
    deck();
    std::shared_ptr<card> dealcard();
    void shuffle();
    void addCard(std::shared_ptr<card> card);
    void showCard() const;

private:
    std::vector<std::shared_ptr<card>> baseCards;
};
