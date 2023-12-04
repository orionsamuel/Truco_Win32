#include "gameController.hpp"
#include <iostream>

GameController::GameController() {
    gameDeck = std::make_shared<Deck>();
    player1 = std::make_shared<Player>();
    player2 = std::make_shared<Player>();
}

void GameController::startGame() {
    for (int i = 0; i < numCardsHand; ++i) {
        player1->drawCard(gameDeck->dealCard());
        player2->drawCard(gameDeck->dealCard());
    }

    std::cout << "Player 1's hand:" << std::endl;
    player1->showHand();
    std::cout << "\nPlayer 2's hand:" << std::endl;
    player2->showHand();
}
