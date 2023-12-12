#include "pch.h"
#include "CmyWnd.h"

CMyWnd::CMyWnd()
{
	Create(NULL, _T("Truco do Pavê"), WS_OVERLAPPEDWINDOW, CRect(100, 100, 400, 400));
	button.Create(_T("Clique"), WS_CHILD | WS_VISIBLE, CRect(10, 10, 100, 30), this, 1);
	editTextfield.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(10, 40, 100, 60), this, 2);
}

BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_COMMAND(1, OnButtonClick)
END_MESSAGE_MAP()

void CMyWnd::OnButtonClick()
{
	CString sWindowText;
	editTextfield.GetWindowText(sWindowText);
	AfxMessageBox(_T("Botao pressionado: " + sWindowText));
}
