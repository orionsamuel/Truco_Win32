#include "cardController.h"
#include "pch.h"

#include<iostream>

cardController::cardController(bool isVertical, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID) : randomEngine(std::random_device{}()) {
	_cardView = new cardView(isVertical, positionX, positionY, pParentWnd, nID);
}

void cardController::createCard(Suit suit, Value value)
{
	try {
		_card.setSuit(suit);
		_card.setValue(value);
	}
	catch (const std::exception& e) {
		std::cerr << "Error creating card: " << e.what() << std::endl;
	}
}

void cardController::displayCard()
{
	try {
		_cardView->displayCard(&_card);
	}
	catch (const std::exception& e) {
		std::cerr << "Error displaying card: " << e.what() << std::endl;
	}
}

card cardController::getCard()
{
	return _card;
}

Suit cardController::getSuit()
{
	try {
		std::uniform_int_distribution<int> distribution(1, static_cast<int>(Suit::DIAMONDS));
		return static_cast<Suit>(distribution(randomEngine));
	}
	catch (const std::exception& e) {
		std::cerr << "Error getting suit: " << e.what() << std::endl;
		return Suit::DIAMONDS;
	}
}

Value cardController::getValue()
{
	try {
		std::uniform_int_distribution<int> distribution(1, static_cast<int>(Value::KING));
		return static_cast<Value>(distribution(randomEngine));
	}
	catch (const std::exception& e) {
		std::cerr << "Error getting value: " << e.what() << std::endl;
		return Value::KING;
	}
}

void cardController::generateCard() {
	_card.setValue(static_cast<Value>(getRandomNumber(1, static_cast<int>(Value::KING))));
	_card.setSuit(static_cast<Suit>(getRandomNumber(1, static_cast<int>(Suit::DIAMONDS))));
}

int cardController::cardController::getRandomNumber(int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(randomEngine);
}