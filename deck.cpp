#include "deck.hpp"
#include <string>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
    for (int i = static_cast<int>(Suit::SPADES); i <= static_cast<int>(Suit::DIAMONDS); ++i) {
        for (int j = static_cast<int>(Value::ACE); j <= static_cast<int>(Value::KING); ++j) {
            std::shared_ptr<Card> newCard = std::make_shared<Card>();
            newCard->setSuit(static_cast<Suit>(i));
            newCard->setValue(static_cast<Value>(j));
            cards.push_back(newCard);
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