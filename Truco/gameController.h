#pragma once

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

#include "game.h"
#include "handController.h"
#include "teamController.h"
#include "gameView.h"

class gameController {
public:
	gameController() = default;
	gameController(CFrameWnd* pParentWnd, UINT nID);

	void createGame(int playerCount);
	void saveGame(const std::string& filename);
	void loadGame(const std::string& filename);
	void showScore();
	void showWinner();

	void executeAction(WPARAM wParam);

private:
	CFrameWnd* _parentWindow;
	UINT _gameBaseId;

	gameView _gameView;
	game _game;
	handController _handSettings;
	teamController _teamSettings;

	int _maxScore = 12;
	
	void loadPlayers(int quantity);
	void drawGame();
	std::string getScoreData();
	std::string getSetScoreData();
	bool hasGameFinished();
};
