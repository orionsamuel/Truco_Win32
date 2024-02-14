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
	void executeHandAction(WPARAM wParam);

private:
	CFrameWnd* _parentWindow;
	UINT _handId;

	hand _hand;
	handView _handView;
	teamController* _teamSettings;
	deckController _deckSettings;

	int _teamIndex = 0;
	int _playerIndex = 0;

	void createShuffledDeck();
	void distributeCards();
	void setManilha();
	void setStarterPlayer(playerController player);
	void createSet();
	void setTrucoPlayer(playerController player);
	void setSetValue();
	void setTeamScore();
	void setCurrentPlayer();
};

