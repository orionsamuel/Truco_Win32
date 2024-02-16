#include "pch.h"
#include "setController.h"

void setController::setCurrentPlayer(playerController player)
{
	_currentPlayer = player;
}

playerController setController::getCurrentPlayer()
{
	return _currentPlayer;
}

void setController::setManilhaCard(cardController manilha)
{
	_manilhaCard = manilha;
}

void setController::startSet() {
	_currentPlayer.enableToSelectCard();
}

void setController::reloadSetMoves()
{
	_remainingMoves = 4;
}

void setController::playCard(WPARAM wParam) {
	if (_remainingMoves == 4) {
		_bestCard = _currentPlayer.dealCard(wParam);
		_winnerPlayer = _currentPlayer;
	}
	else {
		auto currCard = _currentPlayer.dealCard(wParam);
		setWinnerCard(currCard);
	}
}

void setController::setWinnerCard(cardController card)
{
	if (_manilhaCard.getValue() == _bestCard.getValue()) {
		//change best card if current best card value and the card value are the same but the best card suit is less than the card suit
		if (_bestCard.getValue() == card.getValue() && _bestCard.getSuit() < card.getSuit()) {
			_bestCard = card;
			_winnerPlayer = _currentPlayer;
		}
	}
	//Selected card is manilha
	else if (_manilhaCard.getValue() == card.getValue()) {
		_bestCard = card;
		_winnerPlayer = _currentPlayer;
	}
	else {
		//change best card if current best card value is less than the card value
		if (_bestCard.getValue() < card.getValue()) {
			_bestCard = card;
			_winnerPlayer = _currentPlayer;
		}
		else if (_bestCard.getValue() == card.getValue() && _bestCard.getSuit() < card.getSuit()) {
			//change best card if current best card value and the card value are the same but the best card suit is less than the card suit
			_bestCard = card;
			_winnerPlayer = _currentPlayer;
		}
	}
}

bool setController::setIsFinished() const
{
	return _remainingMoves <= 0;
}

playerController setController::getSetWinnerPlayer()
{
	return _winnerPlayer;
}

void setController::executeSetAction(WPARAM wParam)
{
	int diff = wParam - _currentPlayer.playerId;
	if (diff >= 0 && diff < 10) {
		playCard(wParam);
		_remainingMoves--;
	}
}
