#include "pch.h"
#include "cardView.h"

cardView::cardView(int positionX, int positionY, int selectedPosX, int selectedPosY, CFrameWnd* pParentWnd, UINT nID)
{
	_positionX = positionX;
	_positionY = positionY;
	_selectedPosX = selectedPosX;
	_selectedPosY = selectedPosY;
	_parentWindow = pParentWnd;
	_cardId = nID;
}

void cardView::displayCard(card* cardModel, bool isEnabled) const
{
	CString cardText = CString(cardModel->getCardDescription().c_str());
	_card->create(cardText, _positionX, _positionY, _parentWindow, _cardId);

	_card->enableButton(isEnabled);
}

void cardView::enableCard(bool isEnabled) const
{
	_card->enableButton(isEnabled);
}

void cardView::selectCard() const
{
	_card->moveButton(_selectedPosX, _selectedPosY);
}

void cardView::deselectCard() const
{
	_card->reloadButtonPosition();
}
