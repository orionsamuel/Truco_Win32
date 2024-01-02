#pragma once
#include<memory>
#include<vector>

#include "hand.h"
#include "player.h"
#include "team.h"

class game {
public:
	game() = default;

	player winnerPlayer;
	std::vector<std::shared_ptr<player>> playerList;
	std::vector<std::shared_ptr<hand>> handList;
	std::vector<std::shared_ptr<team>> teamList;
};
