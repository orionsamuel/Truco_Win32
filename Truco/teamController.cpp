#include "pch.h"
#include "teamController.h"


void teamController::createTeam(std::string name) {
	std::shared_ptr<team> newTeam = std::make_shared<team>();
	newTeam->teamName = name;
	newTeam->score = 0;
	newTeam->teamId = teamList.size(); // Confirm the logic of this attribute
	teamList.emplace_back(newTeam);
}

std::string teamController::getTeamName(int teamId) const {
	if (teamList.size() > teamId) {
		return teamList[teamId]->teamName;
	}
	return std::string();
}

void teamController::addPlayers(int teamId, playerController playerSettings)
{
	if (!teamList.empty() && teamList.size() > teamId)
	{
		teamList[teamId]->members.push_back(std::make_shared<playerController>(playerSettings));
	}
}

void teamController::showAllPlayers()
{
	for (auto& team : teamList)
	{
		showTeamPlayers(team->teamId);
	}
}

void teamController::showTeamPlayers(int teamId) {
	if (!teamList[teamId]->members.empty()) {
		for (auto& player : teamList[teamId]->members) {
			player->displayPlayer();
		}
	}
}

std::shared_ptr<playerController> teamController::getPlayer(std::string playerName) {
	for (auto& team : teamList)
	{
		for (auto& player : team->members) {
			if (player->getName()._Equal(playerName)) {
				return player;
			}
		}
	}
	return std::shared_ptr<playerController>();
}

int teamController::getTeamListCount()
{
	return teamList.size();
}

int teamController::showScore(int teamId) {
	for (auto& team : teamList)
	{
		if (team->teamId == teamId) {
			return team->score;
		}
	}
	return -1;
}

void teamController::giveScoreToWinner(int score, playerController winner) {
	for (auto& team : teamList)
	{
		for (auto& player : team->members) {
			if (player->getName()._Equal(winner.getName())) {
				team->score += score;
			}
		}
	}
}

void teamController::distributeCards(deckController* deckSettings) {
	const int max_card_number = 3;
	for (int i = 0; i < max_card_number; i++) {
		for (auto& team : teamList)
		{
			for (auto& player : team->members) {
				player->addCard(deckSettings->popCard());
			}
		}
	}
}