#include "pch.h"
#include "setController.h"

void setController::setCurrentPlayer(playerController player) {
	currentPlayer = player;
}

playerController setController::getCurrentPlayer() {
	return currentPlayer;
}

void setController::startSet() {
	//What should we do with that?
}

void setController::playCard() {
	deckSettings.addCard(currentPlayer.dealCard());
}