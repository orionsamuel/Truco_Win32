#include "pch.h"
#include "gameView.h"

void gameView::displayTeamScore(std::string scoreText, CFrameWnd* pParentWnd, UINT nID)
{
	int posX = 30;
	int posY = 30;
	int width = 200;
	int height = 100;

	CString teamScore = CString(scoreText.c_str());

	CStatic* label = new CStatic{};
	label->Create(teamScore, WS_CHILD | WS_VISIBLE, CRect(posX, posY, width, height), pParentWnd, nID);
}
