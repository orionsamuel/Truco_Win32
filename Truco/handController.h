#pragma once
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
	void setStarterPlayer();
	void createSet();
	void setTrucoPlayer();
	void setSetValue();
	void setTeamScore();
public:
	void createGame();
};

