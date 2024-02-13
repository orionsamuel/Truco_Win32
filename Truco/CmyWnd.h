#pragma once
#include <string>

#include "customButton.h"
#include "gameController.h"

class CMyWnd : public CFrameWnd
{
public:
	CMyWnd();
	afx_msg void OnButtonClick();
	DECLARE_MESSAGE_MAP()

	BOOL OnCommand(WPARAM wParam, LPARAM lParam);

private:
	CStatic* _titleLabel = new CStatic{};
	customButton* _startButton = new customButton(150, 50);
	gameController _gameControl;

	void createTitle(CFrameWnd* parent);
	void ExecuteActionById(WPARAM wParam);
};