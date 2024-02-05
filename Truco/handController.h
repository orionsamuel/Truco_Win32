#pragma once
#include "playerController.h"
#include "teamController.h"
#include "hand.h"
#include "setController.h"

class handController
{
private:
	hand hand;
	teamController teamSettings;
	deckController deckSettings;
	void createShuffledDeck();
	void distributeCards();
	void setManilha();
	void setStarterPlayer(playerController player);
	void createSet();
	void setTrucoPlayer(playerController player);
	void setSetValue();
	void setTeamScore();
public:
	void createGame();
};

