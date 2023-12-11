#include "player.hpp"
#include <iostream>

Player::Player() {
    score = 0;
}

void Player::drawCard(std::shared_ptr<Card> card) {
    hand.push_back(card);
}

void Player::showHand() {
    std::cout << "Player's hand:" << std::endl;
    for (const auto& card : hand) {
        card->displayCard();
    }
}

void Player::setScore() {
    score++;
}

int Player::getScore() {
    return score;
}
