#ifndef DECK_H
#define DECK_H

#include "card.hpp"
#include <memory>
#include <vector>

class Deck {
public:
    Deck();
    void displayDeck();

private:
    std::vector<std::shared_ptr<Card>> cards;
};

#endif // DECK_H
