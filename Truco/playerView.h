#pragma once
#include <string>

#include "player.h"

class playerView
{
public:
	playerView() = default;
	playerView(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);
	void displayPlayerName(player player) const;

private:
	int _positionX;
	int _positionY;
	CFrameWnd* _parentWindow;
	UINT _playerId;
};

