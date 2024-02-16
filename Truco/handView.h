#pragma once
#include <string>

#include "hand.h"
#include "converters.h"

class handView
{
public:
	void displayView(hand handModel, CFrameWnd* pParentWnd, UINT nID);
	void enableTrucoButton(bool isEnabled = true);

private:
	customButton* _trucoButton = new customButton(150, 50);
};

