#include "gameController.hpp"
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

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

    playRound(player1, 1);
}

void GameController::playRound(std::shared_ptr<Player> currentPlayer, int currentPlayerNumber) {
    //Game turn rules
    currentPlayer->setScore();

    //Define stop condition
    if(player1->getScore() >= maxScore || player2->getScore() >= maxScore){
        std::cout << "Game Over! Final scores - Player 1: " << player1->getScore() << " | Player 2: " << player2->getScore() << std::endl;
        return;
    }

    int nextPlayerNumber = (currentPlayerNumber == 1) ? 2 : 1;
    std::shared_ptr<Player> nextPlayer = (nextPlayerNumber == 1) ? player1 : player2;

    saveGame("game_state.txt");
    playRound(nextPlayer, nextPlayerNumber);

}

void GameController::saveGame(const std::string& filename) {
    try {
        fs::path filePath = fs::current_path() / filename;
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << "Score Player 1: " << player1->getScore() << std::endl;
            file << "Score Player 2: " << player2->getScore() << std::endl;
            file.close();
            std::cout << "Game state saved successfully.\n";
        } else {
            std::cerr << "Unable to save game state to file.\n";
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error saving game state: " << ex.what() << std::endl;
    }
}

void GameController::loadGame(const std::string& filename) {
    try {
        fs::path filePath = fs::current_path() / filename;
        if (fs::exists(filePath)) {
            std::ifstream file(filePath);
            if (file.is_open()) {
                std::string line;
                std::cout << "Game state loaded:\n";
                while (std::getline(file, line)) {
                    std::cout << line << std::endl; 
                }
                file.close();
            }
        } else {
            std::cerr << "File doesn't exist.\n";
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error loading game state: " << ex.what() << std::endl;
    }
}