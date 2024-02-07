#include "pch.h"
#include "handController.h"
#include <random>

bool notDuplicatedCard(int, std::vector<cardController>);

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

void handController::setStarterPlayer(playerController player) {
	hand.startPlayer = player;
}

void handController::createSet() {
	setController setSettings;

	setSettings.setCurrentPlayer(hand.startPlayer);

	hand.setList.push_back(std::make_shared<setController>(setSettings));
}

void handController::setTrucoPlayer(playerController player) {
	hand.trucoPlayer = player;
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
	//setStarterPlayer(); //Who should choose the starter player? hand or game?
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