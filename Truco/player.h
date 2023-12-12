#pragma once

#include "card.h"
#include <vector>
#include <memory>

class Player {
public:
    Player() = default;
    void drawCard(std::shared_ptr<Card> card);
    void showHand() const;
    void setScore();
    int getScore() const;

private:
    std::vector<std::shared_ptr<Card>> hand;
    int score = 0;
};
