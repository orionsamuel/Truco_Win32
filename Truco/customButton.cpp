#include "pch.h"
#include "customButton.h"

customButton::customButton()
{
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

void customButton::create(bool isVertical, CString label, int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	_isVertical = isVertical;
	_label = label;
	_buttonId = nID;

	_initialPositionX = positionX;
	_initialPositionY = positionY;

	// if vertical element, the size is 50x100, else is 100x50
	_width = _isVertical ? _size50 : _size100;
	_height = _isVertical ? _size100 : _size50;

	//CButton::Create(label, WS_CHILD | WS_VISIBLE, createButtonRect(positionX, positionY), pParentWnd, nID);
	this->Create(label, WS_CHILD | WS_VISIBLE, createButtonRect(positionX, positionY), pParentWnd, nID);
}

void customButton::enableButton(bool isEnabled)
{
	this->EnableWindow(isEnabled);
}

void customButton::collapseButton()
{
	this->ShowWindow(SW_HIDE);
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