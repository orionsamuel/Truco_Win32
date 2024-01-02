#include "pch.h"
#include "gameController.h"
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void gameController::createGame()
{
    try {
        handSettings.createGame();
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating game: " << e.what() << std::endl;
    }
}

void gameController::loadPlayers(int quantity)
{
    try {
        for (int i = 0; i < quantity; i++) {
            players.push_back(std::make_shared<playerController>());
            players[i]->createPlayer("Player " + std::to_string(i + 1));
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error loading players: " << e.what() << std::endl;
    }
}

void gameController::startGame() 
{
    try {
        handSettings.setStartPlayer();
        handSettings.setManilha();
    }
    catch (const std::exception& e) {
        std::cerr << "Error starting game: " << e.what() << std::endl;
    }
}

void gameController::showScore()
{
    try {
        for (int i = 0; i < teamSettings.length; i++) {
            std::cout << "Team " << i + 1 << " score: " << teamSettings[i].showScore() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error showing score: " << e.what() << std::endl;
    }
}

void gameController::addHandToList()
{

}

void gameController::showWinner()
{
    try {
        TeamController* winner = nullptr;

        for (auto& team : teamSettings) {
            int currentScore = team.getScore();

            if (currentScore >= 12) {
                winner = &team;
            }
        }

        if (winner != nullptr) {
            std::cout << "Team " << winner->getTeamName() << " is the winner with a score of " << winner->getScore() << std::endl;
        }
        else {
            std::cout << "No winner yet." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error showing winner: " << e.what() << std::endl;
        // Trate a exceção de acordo, por exemplo, registre-a ou lance novamente
    }
}

void gameController::saveGame(const std::string& filename) 
{
    try {
        fs::path filePath = fs::current_path() / filename;
        std::ofstream file(filePath);
        if (file.is_open()) {
            for (int i = 0; i < teamSettings.size(); ++i) {
                file << "Team " << i + 1 << " Score: " << teamSettings[i]->getScore() << "\n";
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

void gameController::loadGame(const std::string& filename) 
{
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