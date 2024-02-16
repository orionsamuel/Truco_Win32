#pragma once
#include "deckController.h"
#include "playerController.h"

class setController
{
private:
	cardController _bestCard;
	cardController _manilhaCard;
	playerController _currentPlayer;
	playerController _winnerPlayer;
	int _remainingMoves = 4;

	void playCard(WPARAM wParam);
	void setWinnerCard(cardController card);

public:
	void setCurrentPlayer(playerController player);
	playerController getCurrentPlayer();
	void setManilhaCard(cardController manilha);
	void startSet();
	void reloadSetMoves();
	bool setIsFinished() const;
	playerController getSetWinnerPlayer();

	void executeSetAction(WPARAM wParam);
};

