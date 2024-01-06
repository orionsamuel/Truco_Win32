#include "pch.h"
#include "setController.h"

void setController::setCurrentPlayer(playerController player) {
	currentPlayer = player;
}

playerController setController::getCurrentPlayer() {
	return currentPlayer;
}

void setController::startSet() {

}

void setController::playCard() {
	deckSettings.addCard(currentPlayer.dealCard());
}