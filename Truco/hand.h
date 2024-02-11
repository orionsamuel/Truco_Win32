#pragma once
#include <vector>
#include "setController.h"

class hand{
public:
    cardController manilha;
    std::vector<std::shared_ptr<setController>> setList;
    playerController winner;
    int setValue;
    playerController trucoPlayer;
    playerController startPlayer;
};

