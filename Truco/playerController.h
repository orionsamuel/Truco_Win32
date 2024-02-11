#pragma once
#include<string>

#include "cardController.h"
#include "deckController.h"
#include "player.h"

class playerController {
public:
	playerController() = default;

	void createPlayer(std::string name);
	void addCard(cardController card);
	cardController dealCard(); 
	std::string getName();

	deckController deckSettings;

private:
	player p;
};