#include "pch.h"
#include "cardView.h"

cardView::cardView(bool isVertical, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_isVerticalCard = isVertical;
	_positionX = positionX;
	_positionY = positionY;
	_parentWindow = pParentWnd;
	_cardId = nID;
}

void cardView::displayCard(card* cardModel) const
{
	CString cardText = CString(cardModel->getCardDescription().c_str());
	_card->create(_isVerticalCard, cardText, _positionX, _positionY, _parentWindow, _cardId);
}
