#include "pch.h"
#include "player.h"
#include <iostream>

void player::drawcard(std::shared_ptr<card> card)
{
    hand.push_back(card);
}

void player::showHand() const
{
    std::cout << "player's hand:" << std::endl;
    for (const auto& card : hand)
    {
        card->displaycard();
    }
}

void player::setScore()
{
    score++;
}

int player::getScore() const
{
    return score;
}
