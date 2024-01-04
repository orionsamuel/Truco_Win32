#pragma once
#include <afxbutton.h>

class customButton : public CButton
{
public:
	customButton();
	~customButton();

	bool getSelectedStatus();
	void setSelectedStatus(bool isSelected);

	void create(bool isVertical, CString label, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);
	void enableButton(bool isEnabled);
	void collapseButton();
	void moveButton(int newPositionX, int newPositionY);
	void reloadButtonPosition();

private:
	UINT _buttonId;
	CString _label;

	bool _isVertical = true;
	bool _isSelected = false;

	int _initialPositionX = 0;
	int _initialPositionY = 0;

	int _size50 = 50;
	int _size100 = 100;

	int _width = 0;
	int _height = 0;

	CRect createButtonRect(int positionX, int positionY) const;
};

