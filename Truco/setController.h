#pragma once
#include "deckController.h"
#include "playerController.h"

class setController
{
private:
	deckController deckSettings;
	playerController currentPlayer;
	int _remainingMoves = 4;

	void playCard(WPARAM wParam);

public:
	void setCurrentPlayer(playerController player);
	playerController getCurrentPlayer();
	void startSet();
	void reloadSetMoves();
	bool setIsFinished() const;

	void executeSetAction(WPARAM wParam);
};

