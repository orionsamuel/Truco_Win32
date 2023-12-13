#include "pch.h"
#include "player.h"
#include <iostream>

void Player::drawCard(std::shared_ptr<Card> card)
{
    hand.push_back(card);
}

void Player::showHand() const
{
    std::cout << "Player's hand:" << std::endl;
    for (const auto& card : hand)
    {
        card->displayCard();
    }
}

void Player::setScore()
{
    score++;
}

int Player::getScore() const
{
    return score;
}
