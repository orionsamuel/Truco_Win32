#include "pch.h"
#include "CmyWnd.h"

int maxWidth = 1350;
int maxHeight = 700;

CMyWnd::CMyWnd()
{
	Create(NULL, _T("Truco do Pavê"), WS_OVERLAPPEDWINDOW, CRect(10, 10, maxWidth, maxHeight));

	createTitle(this);

	_startButton->create(_T("Play Game"), maxWidth/2 - 75, 320, this, 1);

	_gameControl = gameController(this, 10);
}


BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_COMMAND(1, OnButtonClick)
END_MESSAGE_MAP()

//Evento acionado quando algum botão é clicado
BOOL CMyWnd::OnCommand(WPARAM wParam, LPARAM lParam) {

	//wParam, no OnCommand, corresponde ao id do botão clicado
	if (wParam >= 10)
	{
		ExecuteActionById(wParam);
	}

	return CWnd::OnCommand(wParam, lParam);
}

void CMyWnd::createTitle(CFrameWnd* parent) {
	std::string titleText = "Bem vindo ao Truco do Pavê!\r\nClique no botão abaixo para iniciar";
	CString title = CString(titleText.c_str());

	int width = 300;
	int height = 60;
	int left = maxWidth/2 - 150;
	int top = 250;
	_titleLabel->Create(title, WS_CHILD | WS_VISIBLE, CRect(left, top, left + width, top + height), parent, 1);
}

/// <summary>
/// Executa ação de botão pelo Id dele
/// </summary>
/// <param name="wParam">Id do botão clicado</param>
void CMyWnd::ExecuteActionById(WPARAM wParam)
{
	_gameControl.executeAction(wParam);
}

void CMyWnd::OnButtonClick()
{
	_titleLabel->DestroyWindow();
	_startButton->DestroyWindow();

	_gameControl.createGame(2);
}
