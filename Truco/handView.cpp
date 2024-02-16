#include "pch.h"
#include "handView.h"

void handView::displayView(hand handModel, CFrameWnd* pParentWnd, UINT nID)
{
	handModel.keyCard.displayCard();
	handModel.keyCard.enableCard(false);

	std::string manilha = "The manilha card is: " + converters::convertValueToString(handModel.manilha.getValue());

	CString manilhaValue = CString(manilha.c_str());

	CStatic* label = new CStatic{};
	int width = 250;
	int posX = 1350 / 2 - width / 2;
	label->Create(manilhaValue, WS_CHILD | WS_VISIBLE, CRect(posX, 120, posX + width, 140), pParentWnd, nID);
}
