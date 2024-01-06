#pragma once
#include <string>

class team {
public:
    int teamId;
    std::string teamName;
    std::vector<std::shared_ptr<playerController>> members;
    int score;
};

