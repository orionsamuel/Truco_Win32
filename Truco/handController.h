#pragma once
#include "playerController.h"
#include "teamController.h"
#include "hand.h"
#include "setController.h"
#include "handView.h"

class handController
{
public:
	handController() = default;
	handController(CFrameWnd* pParentWnd, UINT nID);

	void createGame(teamController* teamList);
	void displayHand();

private:
	CFrameWnd* _parentWindow;
	UINT _handId;

	hand _hand;
	handView _handView;
	teamController* _teamSettings;
	deckController _deckSettings;

	void createShuffledDeck();
	void distributeCards();
	void setManilha();
	void setStarterPlayer(playerController player);
	void createSet();
	void setTrucoPlayer(playerController player);
	void setSetValue();
	void setTeamScore();

};

