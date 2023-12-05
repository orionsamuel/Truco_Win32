#ifndef PLAYER_H
#define PLAYER_H

#include "card.hpp"
#include <vector>
#include <memory>

class Player {
public:
    Player();
    void drawCard(std::shared_ptr<Card> card);
    void showHand();
    void setScore();
    int getScore();

private:
    std::vector<std::shared_ptr<Card>> hand;
    int score;
};

#endif // PLAYER_H
