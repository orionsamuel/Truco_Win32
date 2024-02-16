#pragma once
#include <string>

class gameView
{
public:
	void displayTeamScore(std::string scoreText, CFrameWnd* pParentWnd, UINT nID);
	void updateTeamScore(std::string scoreText);

	void displaySetScore(std::string scoreText, CFrameWnd* pParentWnd, UINT nID);
	void updateSetScore(std::string scoreText);

private:
	CStatic* _scoreLabel;
	CStatic* _setScoreLabel;
};

