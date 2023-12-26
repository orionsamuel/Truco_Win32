#include "pch.h"
#include "CmyWnd.h"
#include "cardController.h"

CMyWnd::CMyWnd()
{
	Create(NULL, _T("Truco do Pavê"), WS_OVERLAPPEDWINDOW, CRect(100, 100, 400, 400));
	
	c = card();
	cv = cardView(this);
	cc = cardController(c, cv);
}

BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_COMMAND(1, OnButtonClick)
END_MESSAGE_MAP()

void CMyWnd::OnButtonClick()
{
	cc.displayCard();
}