#pragma once
#include<string>

#include "cardController.h"
#include "deckController.h"
#include "player.h"
#include "playerView.h"

class playerController {
public:
	UINT playerId;

	playerController() = default;
	playerController(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);

	void createPlayer(std::string name, bool isCpu = false);
	void addCard(cardController card);
	cardController dealCard(int cardId);
	std::string getName();
	void displayPlayer();
	void enableToSelectCard() const;
	void clearDeck();
	void removedSelectedCard() const;

private:
	deckController _deckSettings;
	player _player;
	playerView _playerView;
};