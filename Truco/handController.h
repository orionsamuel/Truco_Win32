#pragma once
#include <mmsystem.h>

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
	void loadNewSet();
	void displayHand();
	void executeHandAction(WPARAM wParam);
	bool hasHandFinished();
	int getHandWorth();

private:
	CFrameWnd* _parentWindow;
	UINT _handId;

	hand _hand;
	handView _handView;
	teamController* _teamSettings;
	deckController _deckSettings;

	int _teamIndex = 0;
	int _playerIndex = 0;
	int _remainingSets = 3;

	void createShuffledDeck();
	void distributeCards();
	void setManilha();
	void setStarterPlayer(playerController player);
	void createSet();
	void setTrucoPlayer(playerController player);
	void setHandValue();
	void playTrucoSound();
	void setTeamSetScore();
	void setTeamScore();
	void setCurrentPlayer();
};

