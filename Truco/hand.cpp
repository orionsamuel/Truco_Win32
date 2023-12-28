#include "pch.h"
#include "hand.h"

#pragma region Constructors
hand::hand() = default;
#pragma endregion

#pragma region Getters

card hand::getManilha() const {
	return this->manilha;
}

std::vector<set> hand::getSetList() const {
	return this->setList;
}

player hand::getWinner() const {
	return this->winner;
}

int hand::getSetValue() const {
	return this->setValue;
}

player hand::getTrucoPlayer() const {
	return this->trucoPlayer;
}

player hand::getStartPlayer() const {
	return this->startPlayer;
}

#pragma endregion

#pragma region Setters

void hand::setManilha(card const& newManilha) {
	this->manilha = newManilha;
}

void hand::addOnSetList(set const& newSet) {
	this->setList.push_back(newSet);
}

void hand::setWinner(player const& newWinner) {
	this->winner = newWinner;
}

void hand::setSetValue(int const& newValue) {
	this->setValue = newValue;
}

void hand::setTrucoPlayer(player const& newTrucoPlayer) {
	this->trucoPlayer = newTrucoPlayer;
}
void hand::setStartPlayer(player const& newStartPlayer) {
	this->startPlayer = newStartPlayer;
}
#pragma endregion
