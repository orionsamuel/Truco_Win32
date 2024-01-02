#pragma once

#include "deck.h"
#include "game.h"
#include "playerController.h"
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

class gameController {
public:
    GameController() = default;
    void createGame();
    void loadPlayers(int quantity);
    void startGame();
    void showScore();
    void addHandToList();
    void showWinner();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

private:
    void createHand();

    game gameSettings;
    /*handController handSettings;
    std::vector< std::shared_ptr <teamController>> teamSettings;*/
    std::vector<std::shared_ptr<playerController>> players;
};
