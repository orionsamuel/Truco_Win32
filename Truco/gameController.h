#pragma once

#include "deck.h"
#include "player.h"
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

class GameController {
public:
    GameController(int numplayers);
    void startGame();
    void playRound();
    bool isGameOver();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

private:
    std::shared_ptr<deck> gamedeck;
    std::vector<std::shared_ptr<player>> players;
    int currentplayerIndex = 0;
    int numberOfplayers;
    const int numcardsHand = 3;
    const int maxScore = 10;
};
