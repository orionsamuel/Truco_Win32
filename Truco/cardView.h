#pragma once
#include "card.h"
//#include "afxwin.h"

class cardView
{
private:
	//CEdit valueTextfield;
	//CEdit suitTextfield;

public:
	cardView();
	explicit cardView(CFrameWnd* parent);
	void displayCard(card c) const;
};

