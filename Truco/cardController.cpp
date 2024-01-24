#include "cardController.h"
#include "pch.h"

#include<iostream>


cardController::cardController(card& c, cardView& cv) : c(c), cv(cv), randomEngine(std::random_device{}()) {}

void cardController::createCard(Suit s, Value v)
{
	try {
		c.suit = s;
		c.value = v;
	}
	catch (const std::exception& e) {
		std::cerr << "Error creating card: " << e.what() << std::endl;
	}
}

void cardController::displayCard()
{
	try {
		cv.displayCard(c);
	}
	catch (const std::exception& e) {
		std::cerr << "Error displaying card: " << e.what() << std::endl;
	}
}

card cardController::getCard()
{
	return c;
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
	c.value = static_cast<Value>(getRandomNumber(1, static_cast<int>(Value::KING)));
	c.suit = static_cast<Suit>(getRandomNumber(1, static_cast<int>(Suit::DIAMONDS)));
}

int cardController::cardController::getRandomNumber(int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(randomEngine);
}