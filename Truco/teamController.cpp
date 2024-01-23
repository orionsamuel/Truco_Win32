#include "pch.h"
#include "teamController.h"


int teamController::createTeam(std::string name) {
	int result;
	std::shared_ptr<team> newTeam = std::make_shared<team>();
	newTeam->teamName = name;
	newTeam->score = 0;
	newTeam->teamId = 0; // Confirm the logic of this attribute
	teamList.emplace_back(newTeam);
	
	result = newTeam->score; // Confirm what should be the output of it
	return result;
}

std::string teamController::getTeamName(team teamName) const {
	return teamName.teamName;
}

void teamController::addPlayers(std::string teamName, std::string name) {
	playerController playerSettings;
	playerSettings.createPlayer(name);

	for (auto& team : teamList)
	{
		if (team->teamName._Equal(teamName)) {
			team->members.push_back(std::make_shared<playerController>(playerSettings));
		}
	}
}

void teamController::addPlayers(std::string name) {
	playerController playerSettings;
	playerSettings.createPlayer(name);
	
	teamList[0]->members.push_back(std::make_shared<playerController>(playerSettings));
}

void teamController::showPlayers() {

}

int teamController::showScore() {
	return 0;
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

void teamController::distributeCards(deckController deckSettings) {
	const int max_card_number = 3;
	for (int i = 0; i < max_card_number; i++) {
		for (auto& team : teamList)
		{
			for (auto& player : team->members) {
				player->addCard(deckSettings.popCard());
			}
		}
	}
}