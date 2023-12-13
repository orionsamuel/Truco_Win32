#include "pch.h"
#include "deck.h"
#include <string>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

deck::deck() {
    for (auto i = static_cast<int>(Suit::SPADES); i <= static_cast<int>(Suit::DIAMONDS); ++i)
    {
        for (auto j = static_cast<int>(Value::ACE); j <= static_cast<int>(Value::KING); ++j)
        {
            auto newcard = std::make_shared<card>();
            newcard->setSuit(static_cast<Suit>(i));
            newcard->setValue(static_cast<Value>(j));
            cards.push_back(newcard);
        }
    }
}

void deck::displaydeck() const
{
    for (auto& card : cards)
    {
        card->displaycard();
    }
}

std::shared_ptr<card> deck::dealcard()
{
    if (cards.empty()) {
        return nullptr;
    }

    std::shared_ptr<card> dealtcard = cards.back();
    cards.pop_back();
    return dealtcard;
}


void deck::shuffle()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}