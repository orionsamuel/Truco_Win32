#include "pch.h"
#include "player.h"

void player::setPlayerType(bool isCpu)
{
	type = isCpu ? PlayerType::CPU : PlayerType::PLAYER;
}
