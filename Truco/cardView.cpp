#include "pch.h"
#include "cardView.h"

cardView::cardView(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_positionX = positionX;
	_positionY = positionY;
	_parentWindow = pParentWnd;
	_cardId = nID;
}

void cardView::displayCard(card* cardModel) const
{
	CString cardText = CString(cardModel->getCardDescription().c_str());
	_card->create(cardText, _positionX, _positionY, _parentWindow, _cardId);
}

void cardView::enableCard(bool isEnabled) const
{
	_card->enableButton(isEnabled);
}
