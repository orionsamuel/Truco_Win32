#pragma once
#include <afxwin.h>
#include "card.h"
#include "customButton.h"

class cardView
{
public:
	cardView() = default;
	cardView(bool isVertical, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);
	void displayCard(card* c) const;

private:
	bool _isVerticalCard;
	int _positionX;
	int _positionY;
	CFrameWnd* _parentWindow;
	UINT _cardId;

	customButton* _card = new customButton();
};

