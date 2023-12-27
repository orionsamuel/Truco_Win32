#pragma once
#include <string>
#include "player.h"

class team {
public:
    team() = default;
    team(int const& teamId, std::string const& teamName, std::vector<player> const& members, int const& score);

    int getId() const;
    std::string getTeamName() const;
    std::vector<player> getMembers() const;
    int getScore() const;

    void setId(int newId);
    void setTeamName(std::string_view const & newName);
    void setMembers(std::vector<player> const & members);
    void setScore(int newScore);
private:
    int teamId;
    std::string teamName;
    std::vector<player> members;
    int score;
};

