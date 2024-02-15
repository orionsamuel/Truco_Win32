#include "pch.h"
#include "setController.h"

void setController::setCurrentPlayer(playerController player) {
	currentPlayer = player;
}

playerController setController::getCurrentPlayer() {
	return currentPlayer;
}

void setController::startSet() {
	currentPlayer.enableToSelectCard();
}

void setController::reloadSetMoves()
{
	_remainingMoves = 4;
}

void setController::playCard(WPARAM wParam) {
	deckSettings.addCard(currentPlayer.dealCard(wParam));
}

bool setController::setIsFinished() const
{
	return _remainingMoves <= 0;
}

void setController::executeSetAction(WPARAM wParam)
{
	int diff = wParam - currentPlayer.playerId;
	if (diff >= 0 && diff < 10) {
		playCard(wParam);
		_remainingMoves--;
	}
}
