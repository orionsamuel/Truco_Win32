#include "pch.h"
#include "handController.h"
#include <random>


void handController::createShuffledDeck() {
	int counter = 0;
	const int max_cards = 13;

	std::vector<cardController> cardSettings(max_cards);
	while (counter < max_cards) {
		cardSettings[counter].generateCard();
		if (notDuplicatedCard(counter, cardSettings)) {
			deckSettings.addCard(cardSettings[counter]);
			counter++;
		}
	}	
}

void handController::distributeCards() {
	teamSettings.distributeCards(deckSettings);
}

void handController::setManilha() {
	hand.manilha = deckSettings.popCard();
}

void handController::setStarterPlayer() {
	// What should be the logic for setting this starter player?
}

void handController::createSet() {
	setController setSettings;

	setSettings.setCurrentPlayer(hand.startPlayer);

	hand.setList.push_back(std::make_shared<setController>(setSettings));
}

void handController::setTrucoPlayer() {
	// Shouldn't it be setTrucoTeam(int id)?
}

void handController::setSetValue() {
	if (hand.setValue > 1 || hand.setValue < 12) {
		hand.setValue += 3;
	}
	else if (hand.setValue == 1) {
		hand.setValue = 3;
	}
}

void handController::setTeamScore() {
	teamSettings.giveScoreToWinner(hand.setValue, hand.winner);
}

void handController::createGame() {
	createShuffledDeck();
	setManilha();
	distributeCards();
	setStarterPlayer();
	hand.setValue = 1;
	createSet();
}

bool notDuplicatedCard(int index, std::vector<cardController> cardSettingsList) {
	int counter = 0;
	cardController newCard = cardSettingsList[index];
	for (auto& cardSettings : cardSettingsList)
	{
		if (cardSettings.getCard().suit == newCard.getCard().suit && cardSettings.getCard().value == newCard.getCard().value) {
			counter++;
		}
	}
	return counter < 2;
}