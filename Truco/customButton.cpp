#include "pch.h"
#include "customButton.h"

customButton::customButton(int width, int height)
{
	_isCustomSize = true;
	_width = width;
	_height = height;
}

customButton::~customButton()
{
}

bool customButton::getSelectedStatus()
{
	return _isSelected;
}

void customButton::setSelectedStatus(bool isSelected)
{
	_isSelected = isSelected;
}

void customButton::create(CString label, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_label = label;
	_buttonId = nID;

	_initialPositionX = positionX;
	_initialPositionY = positionY;

	this->Create(label, WS_CHILD | WS_VISIBLE | BS_MULTILINE | BS_CENTER, createButtonRect(positionX, positionY), pParentWnd, nID);
}

void customButton::enableButton(bool isEnabled)
{
	this->EnableWindow(isEnabled);
}

void customButton::collapseButton()
{
	this->DestroyWindow();
}

void customButton::moveButton(int newPositionX, int newPositionY)
{
	this->MoveWindow(newPositionX, newPositionY, _width, _height);
}

void customButton::reloadButtonPosition()
{
	moveButton(_initialPositionX, _initialPositionY);
}

CRect customButton::createButtonRect(int positionX, int positionY) const
{
	int left = positionX;
	int top = positionY;
	int right = left + _width;
	int bottom = top + _height;

	return CRect(left, top, right, bottom);
}