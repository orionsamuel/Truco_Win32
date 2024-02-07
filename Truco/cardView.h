#pragma once
#include <afxwin.h>
#include "card.h"

class cardView
{
private:
	CEdit* valueTextfield = new CEdit;
	CEdit* suitTextfield = new CEdit;
	CButton* button = new CButton;


public:
	cardView() = default;
	explicit cardView(CFrameWnd* parent);
	void displayCard(card c) const;
};

