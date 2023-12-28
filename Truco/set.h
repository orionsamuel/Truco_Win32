#pragma once

#include "deck.h"
#include "player.h"

class set
{
public:
    set();

    deck getCardList() const;
    player getCurrentPlayer() const;
    player getWinnerPlayer() const;
    card getStrongestCard() const;
    player getStartPlayer() const;

    void setCardList(deck const& newCardList);
    void setCurrentPlayer(player const& newCurrentPlayer);
    void setWinnerPlayer(player const& newWinnerPlayer);
    void setStrongestCard(card const& newStrongestCard);
    void setStartPlayer(player const& newStartPlayer);
private:
    deck cardList;
    player currentPlayer;
    player winnerPlayer;
    card strongestCard;
    player startPlayer;
};

