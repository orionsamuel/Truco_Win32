#pragma once
#include <vector>
#include "team.h"
#include <string>
#include "playerController.h"

class teamController
{
private:
	std::vector<std::shared_ptr<team>> teamList;
public:
	int createTeam(std::string name);
	void addPlayers(std::string teamName, std::string name);
	void addPlayers(std::string name);
	void showPlayers();
	void showScore();
	void giveScoreToWinner(int score, playerController winner);
	void distributeCards(deckController deckSettings);
};

