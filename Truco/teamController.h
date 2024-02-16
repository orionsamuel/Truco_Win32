#pragma once
#include <vector>
#include "team.h"
#include <string>
#include "playerController.h"

class teamController
{
public:
	void createTeam(std::string name);

	std::string getTeamName(int teamId) const;
	void addPlayers(int teamId, playerController playerSettings);
	void showAllPlayers();
	void showTeamPlayers(int teamId);
	std::vector<std::shared_ptr<playerController>> getTeamPlayers(int teamId);
	std::shared_ptr<playerController> getPlayer(std::string playerName);
	int getTeamListCount();
	void giveSetScoreToWinner(int score, playerController winner);
	int showSetScore(int teamId);
	int showScore(int teamId);
	void giveScoreToWinner(int score, playerController winner);
	void distributeCards(deckController* deckSettings);

private:
	std::vector<std::shared_ptr<team>> teamList;
};

