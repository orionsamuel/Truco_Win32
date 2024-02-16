#include "pch.h"
#include "playerView.h"


playerView::playerView(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_positionX = positionX;
	_positionY = positionY;
	_parentWindow = pParentWnd;
	_playerId = nID;
}

void playerView::displayPlayerName(player player) const
{
	int width = _positionX + 150;
	int height = _positionY + 40;

	CStatic* label = new CStatic{};
	CString playerName = CString(player.name.c_str());
	label->Create(playerName, WS_CHILD | WS_VISIBLE, CRect(_positionX, _positionY, width, height), _parentWindow, _playerId);
}
