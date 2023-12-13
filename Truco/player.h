#pragma once
#include "card.h"
#include <vector>
#include <memory>

class player {
public:
    player() = default;
    void drawcard(std::shared_ptr<card> card);
    void showHand() const;
    void setScore();
    int getScore() const;

private:
    std::vector<std::shared_ptr<card>> hand;
    int score = 0;
};
