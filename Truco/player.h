#pragma once
#include "card.h"
#include "deck.h"
#include <vector>
#include <memory>
#include <string>

class player {
public:
    player() = default;
    std::string getName();
    void setName(std::string name) const;
    void drawcard(std::shared_ptr<card> card);
    void showCard() const;

private:
    std::string name;
    deck cardList;
};
