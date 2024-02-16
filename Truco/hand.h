#pragma once
#include <vector>
#include "setController.h"

class hand{
public:
    cardController keyCard;
    cardController manilha;
    std::vector<std::shared_ptr<setController>> setList;
    playerController winner;
    int handValue;
    playerController trucoPlayer;
    playerController startPlayer;
};

