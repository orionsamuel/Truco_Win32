#include "pch.h"
#include "gameView.h"

void gameView::displayTeamScore(std::string scoreText, CFrameWnd* pParentWnd, UINT nID)
{
	int posX = 30;
	int posY = 30;
	int width = 200;
	int height = 100;

	CString teamScore = CString(scoreText.c_str());

	_scoreLabel = new CStatic{};
	_scoreLabel->Create(teamScore, WS_CHILD | WS_VISIBLE, CRect(posX, posY, width, height), pParentWnd, nID);
}

void gameView::updateTeamScore(std::string scoreText)
{
	CString teamScore = CString(scoreText.c_str());
	_scoreLabel->SetWindowTextW(teamScore);
}

void gameView::displaySetScore(std::string scoreText, CFrameWnd* pParentWnd, UINT nID)
{
	int posX = 30;
	int posY = 130;
	int width = 200;
	int height = 200;

	CString teamScore = CString(scoreText.c_str());

	_setScoreLabel = new CStatic{};
	_setScoreLabel->Create(teamScore, WS_CHILD | WS_VISIBLE, CRect(posX, posY, width, height), pParentWnd, nID);
}

void gameView::updateSetScore(std::string scoreText)
{
	CString teamScore = CString(scoreText.c_str());
	_setScoreLabel->SetWindowTextW(teamScore);
}
