#include "pch.h"
#include "cardView.h"

cardView::cardView(CFrameWnd* parent)
{
	button->Create(_T("Clique"), WS_CHILD | WS_VISIBLE, CRect(10, 10, 100, 30), parent, 1);
	suitTextfield->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(10, 40, 100, 60), parent, 1);
	valueTextfield->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(10, 70, 100, 90), parent, 2);
}
void cardView::displayCard(card c) const
{
	CString sWindowText;
	CString sWindowText2;
	valueTextfield->GetWindowText(sWindowText);
	suitTextfield->GetWindowText(sWindowText2);
	AfxMessageBox(_T("Carta selecionada: " + sWindowText + " " + sWindowText2));
}
