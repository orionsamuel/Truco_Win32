#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "deck.hpp"
#include "player.hpp"
#include <filesystem>
#include <memory>
#include <string>

class GameController {
public:
    GameController();
    void startGame();
    void playRound(std::shared_ptr<Player> currentPlayer, int currentPlayerNumber);
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

private:
    std::shared_ptr<Deck> gameDeck;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    const int numCardsHand = 3;
    const int maxScore = 10;
};

#endif // GAME_CONTROLLER_H
