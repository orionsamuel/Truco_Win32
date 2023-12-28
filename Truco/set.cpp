#include "pch.h"
#include "set.h"

#pragma region Constructors

set::set() = default;

#pragma endregion

#pragma region Getters

deck set::getCardList() const {
	return this->cardList;
}

player set::getCurrentPlayer() const {
	return this->currentPlayer;
}

player set::getWinnerPlayer() const {
	return this->winnerPlayer;
}

card set::getStrongestCard() const {
	return this->strongestCard;
}

player set::getStartPlayer() const {
	return this->startPlayer;
}

#pragma endregion


#pragma region Setters

void set::setCardList(deck const& newCardList) {
	this->cardList = newCardList;
}

void set::setCurrentPlayer(player const& newCurrentPlayer) {
	this->currentPlayer = newCurrentPlayer;
}

void set::setWinnerPlayer(player const& newWinnerPlayer) {
	this->winnerPlayer = newWinnerPlayer;
}

void set::setStrongestCard(card const& newStrongestCard) {
	this->strongestCard = newStrongestCard;
}

void set::setStartPlayer(player const& newStartPlayer) {
	this->startPlayer = newStartPlayer;
}

#pragma endregion