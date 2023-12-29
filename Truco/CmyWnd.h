#pragma once
#include "cardController.h"

class CMyWnd : public CFrameWnd
{
public:
	CMyWnd();
	afx_msg void OnButtonClick();
	DECLARE_MESSAGE_MAP()

	BOOL OnCommand(WPARAM wParam, LPARAM lParam);

private:
	cardController player1;
	cardController player2;
	cardController player3;
	cardController player4;
	CButton* button = new CButton;

	void ExecuteActionById(WPARAM wParam);
};