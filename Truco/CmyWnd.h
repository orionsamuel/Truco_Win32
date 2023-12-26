#pragma once
#include "card.h"
#include "cardController.h"
#include "cardView.h"

class CMyWnd : public CFrameWnd
{
public:
	CMyWnd();
	afx_msg void OnButtonClick();
	DECLARE_MESSAGE_MAP()

private:
	card c;
	cardController cc;
	cardView cv;
};