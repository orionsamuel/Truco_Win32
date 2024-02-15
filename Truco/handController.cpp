#include "pch.h"
#include "handController.h"

handController::handController(CFrameWnd* pParentWnd, UINT nID)
{
	_parentWindow = pParentWnd;
	_handId = nID;
}

void handController::createGame(teamController* teamList) {
	_teamSettings = teamList;

	createShuffledDeck();
	distributeCards();
	setManilha();

	setCurrentPlayer();

	_hand.setValue = 1;
}

void handController::loadNewSet()
{
	_deckSettings.clear();

	for (auto& player : _teamSettings->getTeamPlayers(0)) {
		player->clearDeck();
	}
	for (auto& player : _teamSettings->getTeamPlayers(1)) {
		player->clearDeck();
	}

	createShuffledDeck();
	distributeCards();
	setManilha();

	setCurrentPlayer();

	_hand.setValue = 1;

	displayHand();
}

void handController::displayHand()
{
	_handView.displayView(_hand, _parentWindow, _handId);

	_teamSettings->showAllPlayers();
	createSet();
}

void handController::executeHandAction(WPARAM wParam)
{
	auto currentSet = _hand.setList.back();
	currentSet->executeSetAction(wParam);

	if (currentSet->setIsFinished()) {
		for (auto& player : _teamSettings->getTeamPlayers(0)) {
			player->removedSelectedCard();
		}
		for (auto& player : _teamSettings->getTeamPlayers(1)) {
			player->removedSelectedCard();
		}

		currentSet->reloadSetMoves();
	}

	setCurrentPlayer();
	currentSet->setCurrentPlayer(_hand.startPlayer);
	currentSet->startSet();

}

void handController::createShuffledDeck() {
	int counter = 0;
	const int max_cards = 13;

	cardController cardSettings;
	while (counter < max_cards) {
		cardSettings.generateCard();
		if (_deckSettings.canAddCard(cardSettings)) {
			_deckSettings.addCard(cardSettings);
			counter++;
		}
	}
}

void handController::distributeCards() {
	_teamSettings->distributeCards(&_deckSettings);
}

void handController::setManilha() {

	int width = 90;
	int posX = 1350 / 2 - width / 2;

	_hand.lastMountCard = cardController(posX, 160, _parentWindow, _handId);

	cardController lastCard = _deckSettings.popCard();
	_hand.lastMountCard.createCard(lastCard.getSuit(), lastCard.getValue());

	int manilhaId = static_cast<int>(lastCard.getValue());
	manilhaId++;
	manilhaId = manilhaId > static_cast<int>(Value::KING) ? 0 : manilhaId;
	_hand.manilha.createCard(Suit::SPADES, static_cast<Value>(manilhaId));
}

void handController::setStarterPlayer(playerController player) {
	_hand.startPlayer = player;
}

void handController::createSet() {
	setController setSettings;

	setSettings.setCurrentPlayer(_hand.startPlayer);

	setSettings.startSet();
	_hand.setList.push_back(std::make_shared<setController>(setSettings));
}

void handController::setTrucoPlayer(playerController player) {
	_hand.trucoPlayer = player;
}

void handController::setSetValue() {
	if (_hand.setValue > 1 || _hand.setValue < 12) {
		_hand.setValue += 3;
	}
	else if (_hand.setValue == 1) {
		_hand.setValue = 3;
	}
}

void handController::setTeamScore() {
	_teamSettings->giveScoreToWinner(_hand.setValue, _hand.winner);
}

void handController::setCurrentPlayer()
{
	int currIndex = 0;
	for (auto& player : _teamSettings->getTeamPlayers(_teamIndex)) {
		if (currIndex == _playerIndex)
		{
			if (_teamIndex == 1)
				_playerIndex = _playerIndex == 0 ? 1 : 0;

			setStarterPlayer(*player);
			break;
		}
		currIndex++;
	}

	_teamIndex = _teamIndex == 0 ? 1 : 0;
}
