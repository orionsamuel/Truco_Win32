#pragma once
#include <vector>
#include "card.h"
#include "player.h"
#include "set.h"

class hand{
public:
    hand();

    card getManilha() const;
    std::vector<set> getSetList() const;
    player getWinner() const;
    int getSetValue() const;
    player getTrucoPlayer() const;
    player getStartPlayer() const;

    void setManilha(card const& manilha);
    void addOnSetList(set const& newSet);
    void setWinner(player const& winner);
    void setSetValue(int const& value);
    void setTrucoPlayer(player const& trucoPlayer);
    void setStartPlayer(player const& startPlayer);
private:
    card manilha;
    std::vector<set> setList;
    player winner;
    int setValue;
    player trucoPlayer;
    player startPlayer;
};

