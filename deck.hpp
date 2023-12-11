#ifndef DECK_H
#define DECK_H

#include "card.hpp"
#include <memory>
#include <vector>

class Deck {
public:
    Deck();
    void displayDeck();
    std::shared_ptr<Card> dealCard();
    void shuffle();

private:
    std::vector<std::shared_ptr<Card>> cards;
};

#endif // DECK_H
