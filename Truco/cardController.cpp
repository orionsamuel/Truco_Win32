#include "cardController.h"
#include "pch.h"

#include<iostream>

std::uniform_int_distribution<int> randomValues(0, 9);
std::uniform_int_distribution<int> randomSuits(0, 3);

cardController::cardController(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID) : randomEngine(std::random_device{}()) {

	srand(time(NULL));

	_cardView = new cardView(positionX, positionY, pParentWnd, nID);
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
	return _card.getSuit();
}

Value cardController::getValue()
{
	return _card.getValue();
}

void cardController::generateCard() {
	_card.setValue(static_cast<Value>(randomValues(randomEngine)));
	_card.setSuit(static_cast<Suit>(randomSuits(randomEngine)));
}

void cardController::enableCard(bool isEnabled) const
{
	_cardView->enableCard(isEnabled);
}
