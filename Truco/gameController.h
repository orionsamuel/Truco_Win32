#pragma once

#include "deck.h"
#include "game.h"
#include "handController.h"
#include "playerController.h"
#include "team.h"
#include "teamController.h"
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

class gameController {
public:
    gameController() = default;
    void createGame();
    void loadPlayers(int quantity);
    void showScore();
    void showWinner();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

    game gameSettings;
    handController handSettings;
    teamController teamSettings;
    std::vector<std::shared_ptr<playerController>> players;
};
