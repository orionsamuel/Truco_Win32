#include "deck.hpp"
#include <string>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

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

std::shared_ptr<Card> Deck::dealCard() {
    if (cards.empty()) {
        return nullptr;
    }

    std::shared_ptr<Card> dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}


void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}