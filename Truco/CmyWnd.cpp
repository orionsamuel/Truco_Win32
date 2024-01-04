#include "pch.h"
#include "CmyWnd.h"
#include "cardController.h"
#include "resource.h"

int maxWidth = 1200;
int maxHeight = 700;

CMyWnd::CMyWnd()
{
	Create(NULL, _T("Truco do Pavê"), WS_OVERLAPPEDWINDOW, CRect(10, 10, maxWidth, maxHeight));
	button->Create(_T("Start"), WS_CHILD | WS_VISIBLE, CRect(10, 10, 100, 30), this, 1);

	int baseId = 10;
	player1 = cardController(this, "player1", baseId, (maxWidth - 200) / 2, maxHeight - 180, true);
	player1.createDeck();

	baseId += 10;
	player2 = cardController(this, "player2", baseId, maxWidth - 150, (maxHeight - 200) / 2, false);
	player2.createDeck();

	baseId += 10;
	player3 = cardController(this, "player3", baseId, (maxWidth - 200) / 2, 10, true);
	player3.createDeck();

	baseId += 10;
	player4 = cardController(this, "player4", baseId, 10, (maxHeight - 200) / 2, false);
	player4.createDeck();

	//botão com background
	CButton* bmpButton1 = new CButton;
	bmpButton1->Create(_T("Bitmap"), WS_CHILD | WS_VISIBLE | BS_BITMAP, CRect(100, 100, 200, 330), this, 3);

	if (bmpButton1->GetBitmap() == NULL)
		bmpButton1->SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));

}

BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_COMMAND(1, OnButtonClick)
END_MESSAGE_MAP()

//Evento acionado quando algum botão é clicado
BOOL CMyWnd::OnCommand(WPARAM wParam, LPARAM lParam) {

	//wParam, no OnCommand, corresponde ao id do botão clicado
	ExecuteActionById(wParam);

	return CWnd::OnCommand(wParam, lParam);
}

/// <summary>
/// Executa ação de botão pelo Id dele
/// </summary>
/// <param name="wParam">Id do botão clicado</param>
void CMyWnd::ExecuteActionById(WPARAM wParam)
{
	if (wParam >= player4.getBaseId()) {
		player4.selectCard(wParam);
	}
	else if (wParam >= player3.getBaseId()) {
		player3.selectCard(wParam);
	}
	else if (wParam >= player2.getBaseId()) {
		player2.selectCard(wParam);
	}
	else if (wParam >= player1.getBaseId()) {
		player1.selectCard(wParam);
	}
}

void CMyWnd::OnButtonClick()
{
	player1.displayCard();
	player2.displayCard();
	player3.displayCard();
	player4.displayCard();

	button->ShowWindow(SW_HIDE);
}