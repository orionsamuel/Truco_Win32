#pragma once
#include <string>
#include <vector>
#include <memory>
#include "playerController.h"

class team {
public:
    int teamId;
    std::string teamName;
    std::vector<std::shared_ptr<playerController>> members;
    int score;
};

