#pragma once
#include <afxwin.h>

class customButton :
    public CButton
{
public:
	customButton() = default;
	customButton(int width, int height);
	~customButton();

	bool getSelectedStatus();
	void setSelectedStatus(bool isSelected);

	void create(CString label, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID);
	void enableButton(bool isEnabled);
	void collapseButton();
	void moveButton(int newPositionX, int newPositionY);
	void reloadButtonPosition();

private:
	UINT _buttonId;
	CString _label;

	bool _isSelected = false;
	bool _isCustomSize = false;

	int _initialPositionX = 0;
	int _initialPositionY = 0;

	int _width = 90;
	int _height = 70;

	CRect createButtonRect(int positionX, int positionY) const;
};

