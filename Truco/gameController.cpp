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

void gameController::showScore()
{
    try {
        for (size_t i = 0; i < teamSettings.teamList.size(); i++) {
            std::cout << "Team " << i + 1 << " score: " << teamSettings.teamList[i]->score << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error showing score: " << e.what() << std::endl;
    }
}

void gameController::showWinner()
{
    try {
        int winner = -1;

        for (int i = 0; i < teamSettings.teamList.size(); ++i) {
            int currentScore = teamSettings.teamList[i]->score;

            if (currentScore >= 12) {
                winner = i;
                break;
            }
        }

        if (winner != -1) {
            std::shared_ptr<team> winnerTeam = std::make_shared<team>(*teamSettings.teamList[winner]);
            std::cout << "Team " << teamSettings.getTeamName(*winnerTeam) << " is the winner with a score of " << winnerTeam->score << std::endl;
        }
        else {
            std::cout << "No winner yet." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error showing winner: " << e.what() << std::endl;
    }
}

void gameController::saveGame(const std::string& filename) 
{
    try {
        fs::path filePath = fs::current_path() / filename;
        std::ofstream file(filePath);
        if (file.is_open()) {
            for (int i = 0; i < teamSettings.teamList.size(); ++i) {
                file << "Team " << i + 1 << " Score: " << teamSettings.teamList[i]->score << "\n";
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