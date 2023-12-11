#pragma once

#include "card.h"
#include <memory>
#include <vector>

class Deck {
public:
    Deck();
    void displayDeck() const;
    std::shared_ptr<Card> dealCard();
    void shuffle();

private:
    std::vector<std::shared_ptr<Card>> cards;
};
