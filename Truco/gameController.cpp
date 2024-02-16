#include "pch.h"
#include "gameController.h"
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

gameController::gameController(CFrameWnd* pParentWnd, UINT nID)
{
	_parentWindow = pParentWnd;
	_gameBaseId = nID;

	_handSettings = handController(pParentWnd, nID + 1);
}

void gameController::createGame(int playerCount)
{
	try {
		loadPlayers(playerCount);
		_handSettings.createGame(&_teamSettings);
		drawGame();
	}
	catch (const std::exception& e) {
		std::cerr << "Error creating game: " << e.what() << std::endl;
	}
}

void gameController::saveGame(const std::string& filename)
{
	try {
		fs::path filePath = fs::current_path() / filename;
		std::ofstream file(filePath);
		if (file.is_open()) {
			for (int i = 0; i < _teamSettings.getTeamListCount(); ++i) {
				file << _teamSettings.getTeamName(i) << " score: " << _teamSettings.showScore(i) << "\n";
			}
			file.close();
			std::cout << "Game state saved successfully.\n";
		}
		else {
			std::cerr << "Unable to save game state to file.\n";
		}
	}
	catch (const std::exception& ex) {
		std::cerr << "Error saving game state: " << ex.what() << std::endl;
	}
}

void gameController::loadGame(const std::string& filename)
{
	try {
		fs::path filePath = fs::current_path() / filename;
		if (fs::exists(filePath)) {
			std::ifstream file(filePath);
			if (file.is_open()) {
				std::string line;
				std::cout << "Game state loaded:\n";
				while (std::getline(file, line)) {
					std::cout << line << std::endl;
				}
				file.close();
			}
		}
		else {
			std::cerr << "File doesn't exist.\n";
		}
	}
	catch (const std::exception& ex) {
		std::cerr << "Error loading game state: " << ex.what() << std::endl;
	}
}

void gameController::showScore()
{
	try {
		for (size_t i = 0; i < _teamSettings.getTeamListCount(); i++) {
			std::cout << _teamSettings.getTeamName(i) << " score: " << _teamSettings.showScore(i) << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error showing score: " << e.what() << std::endl;
	}
}

void gameController::showWinner()
{
	try {
		int winner = -1;

		for (int i = 0; i < _teamSettings.getTeamListCount(); ++i) {
			int currentScore = _teamSettings.showScore(i);

			if (currentScore >= 12) {
				winner = i;
				break;
			}
		}

		if (winner != -1) {
			std::cout << "Team " << _teamSettings.getTeamName(winner) << " is the winner with a score of " << _teamSettings.showScore(winner) << std::endl;
		}
		else {
			std::cout << "No winner yet." << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error showing winner: " << e.what() << std::endl;
	}
}

void gameController::executeAction(WPARAM wParam)
{
	if (wParam >= _gameBaseId + 10) {
		//Players actions
		_handSettings.executeHandAction(wParam);

		_gameView.updateSetScore(getSetScoreData());
	}

	if (_handSettings.hasHandFinished()) {
		_handSettings.loadNewSet();
		_gameView.updateSetScore(getSetScoreData());
		_gameView.updateTeamScore(getScoreData());
	}
}

void gameController::loadPlayers(int quantity)
{
	try {
		int playId = 1;
		bool isCpu = false;
		int positionX = 30;
		int positionY = 500;
		int playerId = _gameBaseId + 10;

		for (int t = 1; t <= 2; t++) {
			_teamSettings.createTeam("Team " + std::to_string(t));
		}

		int teamId = 0;
		for (int p = 0; p < 4; p++) {
			isCpu = playId > quantity;

			std::string name = "[" + _teamSettings.getTeamName(teamId) + "]\r\n";
			name += (isCpu ? "CPU" : "Player") + std::to_string(playId);

			playerController playerSettings(positionX, positionY, _parentWindow, playerId);
			playerSettings.createPlayer(name, isCpu);

			_teamSettings.addPlayers(teamId, playerSettings);

			playId++;
			positionX += 320;
			playerId += 10;
			teamId = teamId == 0 ? 1 : 0;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error loading players: " << e.what() << std::endl;
	}
}

void gameController::drawGame()
{
	_gameView.displayTeamScore(getScoreData(), _parentWindow, _gameBaseId + 2);
	_gameView.displaySetScore(getSetScoreData(), _parentWindow, _gameBaseId + 3);
	_handSettings.displayHand();
}

std::string gameController::getScoreData()
{
	std::string score = "## SCORE ##";
	for (int t = 0; t < _teamSettings.getTeamListCount(); t++) {
		score += "\r\n" + _teamSettings.getTeamName(t) + ": " + std::to_string(_teamSettings.showScore(t)) + " points";
	}

	return score;
}

std::string gameController::getSetScoreData()
{
	std::string score = "## SET SCORE ##";
	for (int t = 0; t < _teamSettings.getTeamListCount(); t++) {
		score += "\r\n" + _teamSettings.getTeamName(t) + ": " + std::to_string(_teamSettings.showSetScore(t)) + " points";
	}

	return score;
}
