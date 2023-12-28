#include "pch.h"
#include "deck.h"
#include <string>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

deck::deck() {}

std::shared_ptr<card> deck::dealcard()
{
    if (cards.empty()) {
        return nullptr;
    }

    std::shared_ptr<card> dealtcard = baseCards.back();
    baseCards.pop_back();
    return dealtcard;
}


void deck::shuffle()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

void deck::addCard(std::shared_ptr<card> card)
{
    baseCards.push_back(card);
}

void deck::showCard() const
{
    baseCards.back()->displaycard();
}