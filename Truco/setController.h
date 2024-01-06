#pragma once
#include "deckController.h"
#include "playerController.h"

class setController
{
private:
	deckController deckSettings;
	playerController currentPlayer;
public:
	void setCurrentPlayer(playerController player);
	playerController getCurrentPlayer();
	void startSet();
	void playCard();
};

