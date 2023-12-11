#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "deck.hpp"
#include "player.hpp"
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

class GameController {
public:
    GameController(int numPlayers);
    void startGame();
    void playRound();
    bool isGameOver();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

private:
    std::shared_ptr<Deck> gameDeck;
    std::vector<std::shared_ptr<Player>> players;
    int currentPlayerIndex = 0;
    int numberOfPlayers;
    const int numCardsHand = 3;
    const int maxScore = 10;
};

#endif // GAME_CONTROLLER_H
