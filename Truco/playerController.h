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
	void changeCardSelection(int cardId);
	cardController dealCard(); 
	std::string getName();
	void displayPlayer() const;
	void enableToSelectCard() const;

private:
	deckController _deckSettings;
	player _player;
	playerView _playerView;
};