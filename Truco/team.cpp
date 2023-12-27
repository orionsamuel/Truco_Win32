#include "pch.h"
#include "team.h"

#pragma region Constructors

team::team() : teamId(0), teamName("Team"), score(0) {}
team::team(int const& teamId, std::string const& teamName, std::vector<player> const& members, int const& score) : teamId(teamId), teamName(teamName), members(members), score(score) {}

#pragma endregion

#pragma region Getters

int team::getId() const {
	return teamId;
}

std::string team::getTeamName() const {
	return teamName;
}

std::vector<player> team::getMembers() const {
	return members;
}

int team::getScore() const {
	return score;
}

#pragma endregion

#pragma region Setters

void team::setId(int newId) {
	this->teamId = newId;
}

void team::setTeamName(std::string_view const & newName) {
	this->teamName = newName;
}

void team::setMembers(std::vector<player> const & newMembers) {
	this->members = newMembers;
}

void team::setScore(int newScore) {
	this->score = newScore;
}

#pragma endregion
