#include "pch.h"
#include "playerController.h"

void playerController::createPlayer(std::string name)
{
	p.name = name;
}

void playerController::addCard(cardController card)
{
	deckSettings.addCard(card);
}

cardController playerController::dealCard()
{
	return deckSettings.popCard();
}

std::string playerController::getName() {
	return p.name;
}