#pragma once

#include "deck.h"
#include "deckController.h"
#include "playerController.h"

class set{
public:
    deckController cardList;
    playerController currentPlayer;
    playerController winnerPlayer;
    cardController strongestCard;
    playerController startPlayer;
};

