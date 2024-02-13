#include "pch.h"
#include "CmyWnd.h"

int maxWidth = 1350;
int maxHeight = 700;

CMyWnd::CMyWnd()
{
	Create(NULL, _T("Truco do Pav�"), WS_OVERLAPPEDWINDOW, CRect(10, 10, maxWidth, maxHeight));

	createTitle(this);

	_startButton->create(_T("Play Game"), maxWidth/2 - 75, 320, this, 1);
	//_startButton->Create(_T("Play Game"), WS_CHILD | WS_VISIBLE, CRect(550, 320, 650, 350), this, 1);

	_gameControl = gameController(this, 10);
}


BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_COMMAND(1, OnButtonClick)
END_MESSAGE_MAP()

//Evento acionado quando algum bot�o � clicado
BOOL CMyWnd::OnCommand(WPARAM wParam, LPARAM lParam) {

	//wParam, no OnCommand, corresponde ao id do bot�o clicado
	if (wParam >= 10)
	{
		ExecuteActionById(wParam);
	}

	return CWnd::OnCommand(wParam, lParam);
}

void CMyWnd::createTitle(CFrameWnd* parent) {
	std::string titleText = "Bem vindo ao Truco do Pav�!\r\nClique no bot�o abaixo para iniciar";
	CString title = CString(titleText.c_str());

	int width = 300;
	int height = 60;
	int left = maxWidth/2 - 150;
	int top = 250;
	_titleLabel->Create(title, WS_CHILD | WS_VISIBLE, CRect(left, top, left + width, top + height), parent, 1);
}

/// <summary>
/// Executa a��o de bot�o pelo Id dele
/// </summary>
/// <param name="wParam">Id do bot�o clicado</param>
void CMyWnd::ExecuteActionById(WPARAM wParam)
{
	/*if (wParam >= player4.getBaseId()) {
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
	}*/
}

void CMyWnd::OnButtonClick()
{
	/*player1.displayCard();
	player2.displayCard();
	player3.displayCard();
	player4.displayCard();
	*/

	_titleLabel->DestroyWindow();
	_startButton->DestroyWindow();

	_gameControl.createGame(2);
}
