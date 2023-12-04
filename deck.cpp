#include "deck.hpp"
#include <string>

Deck::Deck() {
    std::vector<std::string> suits = {"Spades", "Hearts", "Clubs", "Diamonds"};
    std::vector<std::string> values = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Jack", "Queen", "King"};

    for (const auto& suit : suits) {
        for (const auto& value : values) {
            cards.push_back(std::make_shared<Card>(suit, value));
        }
    }
}

void Deck::displayDeck() {
    for (auto& card : cards) {
        card->displayCard();
    }
}
