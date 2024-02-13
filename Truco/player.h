#pragma once
#include <string>
#include "enums.h"

class player {
public:
    std::string name;
    PlayerType type;

    player() = default;
    void setPlayerType(bool isCpu);
};
