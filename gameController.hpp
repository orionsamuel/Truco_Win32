#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "deck.hpp"
#include "player.hpp"
#include <memory>

class GameController {
public:
    GameController();
    void startGame();

private:
    std::shared_ptr<Deck> gameDeck;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    const int numCardsHand = 3;
};

#endif // GAME_CONTROLLER_H
