#pragma once
#include <vector>
#include "team.h"
#include <string>
#include "playerController.h"

class teamController
{
public:
	std::vector<std::shared_ptr<team>> teamList;

	int createTeam(std::string name);
	std::string getTeamName(team teamName) const;
	void addPlayers(std::string teamName, std::string name);
	void addPlayers(std::string name);
	std::vector<std::shared_ptr<playerController>> teamController::showPlayers(int teamId);
	int showScore(int teamId);
	void giveScoreToWinner(int score, playerController winner);
	void distributeCards(deckController deckSettings);
};

