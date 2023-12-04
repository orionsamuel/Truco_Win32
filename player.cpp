#include "player.hpp"
#include <iostream>

Player::Player() {}

void Player::drawCard(std::shared_ptr<Card> card) {
    hand.push_back(card);
}

void Player::showHand() {
    std::cout << "Player's hand:" << std::endl;
    for (const auto& card : hand) {
        card->displayCard();
    }
}
