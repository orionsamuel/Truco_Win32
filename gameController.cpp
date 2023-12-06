#include "gameController.hpp"
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

GameController::GameController(int numPlayers) : numberOfPlayers(numPlayers) {
    gameDeck = std::make_shared<Deck>();
    for (int i = 0; i < numberOfPlayers; ++i) {
        players.push_back(std::make_shared<Player>());
    }
}

void GameController::startGame() {
    for (int i = 0; i < numCardsHand; ++i) {
        for (auto& player : players) {
            player->drawCard(gameDeck->dealCard());
        }
    }

    playRound();
}

void GameController::playRound() {
    //Game turn rules
    players[currentPlayerIndex]->setScore();
    
    //Define stop condition
    if (isGameOver()) {
        std::cout << "Game Over!" << std::endl;
        return;
    }
    
    currentPlayerIndex = (currentPlayerIndex + 1) % numberOfPlayers;

    saveGame("game_state.txt");
    playRound();

}

bool GameController::isGameOver() {
    for (int i = 0; i < players.size(); ++i) {
        if (players[i]->getScore() >= 10) {
            std::cout << "Player " << i + 1 << " wins with 10 points!\n";
            return true;
        }
    }
    return false;
}

void GameController::saveGame(const std::string& filename) {
    try {
        fs::path filePath = fs::current_path() / filename;
        std::ofstream file(filePath);
        if (file.is_open()) {
            for (int i = 0; i < players.size(); ++i) {
                file << "Player " << i + 1 << " Score: " << players[i]->getScore() << "\n";
            }
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