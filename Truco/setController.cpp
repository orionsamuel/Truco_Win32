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

void setController::playCard() {
	deckSettings.addCard(currentPlayer.dealCard());
}

void setController::executeSetAction(WPARAM wParam)
{
	bool actionExecuted = false;

	int diff = wParam - currentPlayer.playerId;
	if (diff >= 0 && diff < 10) {

		currentPlayer.changeCardSelection(wParam);
		actionExecuted = true;
	}
}
