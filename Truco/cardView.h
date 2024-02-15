#pragma once
#include <afxwin.h>
#include "card.h"
#include "customButton.h"

class cardView
{
public:
	cardView() = default;
	cardView(int positionX, int positionY, int selectedPosX, int selectedPosY, CFrameWnd* pParentWnd, UINT nID);
	void displayCard(card* c, bool isEnabled = true) const;
	void enableCard(bool isEnabled = true) const;
	void collapseCard() const;
	void selectCard() const;
	void deselectCard() const;
	bool hasCardSelected() const;

private:
	int _positionX;
	int _positionY;
	int _selectedPosX;
	int _selectedPosY;

	CFrameWnd* _parentWindow;
	UINT _cardId;

	customButton* _card = new customButton();
};

