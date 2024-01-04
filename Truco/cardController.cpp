#include "pch.h"
#include "cardController.h"

cardController::cardController(CFrameWnd* parent, std::string playerName, int baseId, int posX, int posY, bool isVertical)
{
	_parent = parent;

	_playerName = CString(playerName.c_str());
	_cardPosX = posX;
	_cardPosY = posY;
	_isVertical = isVertical;
	_baseId = baseId;
}

void cardController::createDeck()
{
	for (int i = 1; i <= 3; i++) {
		CString card;
		card.Format(L"%d ht", i);
		cards.push_back(card);

		//auto newcard = std::make_shared<CString>(card);
		//cards.push_back(newcard);
	}
}

CRect cardController::createCard(int posX, int posY) const {

	int left = posX;
	int top = posY;

	int right = posX + 50;
	if (!_isVertical) {
		right = posX + 100;
	}

	int bottom = posY + 100;
	if (!_isVertical) {
		bottom = posY + 40;
	}

	return CRect(left, top, right, bottom);
}

void cardController::displayCard()
{
	//espadas = spades
	//copas = heart
	//paus = clubs
	//ouros = diamond

	int id = _baseId;
	int posX = _cardPosX;
	int posY = _cardPosY;

	int labelPosX = posX - 70;
	int labelPosY = posY;
	int width = posX + 30;
	int height = posY + 20;

	CStatic* label = new CStatic{};
	if (!_isVertical) {
		//label->Create(_playerName, WS_CHILD | WS_VISIBLE, CRect(posX - 70, posY, posX + 30, posY + 20), _parent, id);
		labelPosX = posX;
		labelPosY = posY - 30;
		width = posX + 100;
		height = posY - 10;
		//label->Create(_playerName, WS_CHILD | WS_VISIBLE, CRect(posX, posY - 30, posX + 100, posY - 10), _parent, id);
	}

	label->Create(_playerName, WS_CHILD | WS_VISIBLE, CRect(labelPosX, labelPosY, width, height), _parent, id);

	for (auto& c : cards) {

		id++;

		//LPCTSTR name = (LPCTSTR)c->c_str();

		/*CButton* newButton = new CButton;
		newButton->Create(c, WS_CHILD | WS_VISIBLE, createCard(posX, posY), _parent, id);*/
		//buttons.insert(std::make_pair(id, newButton));

		customButton* newButton = new customButton;
		newButton->create(_isVertical, c, posX, posY, _parent, id);
		buttons.insert(std::make_pair(id, newButton));

		if (_isVertical) {
			posX += 60; //position X + card width + margin 10
		}
		else {
			posY += 60; //position X + card height + margin 10
		}

	}
}

int cardController::getBaseId()
{
	return _baseId;
}

void cardController::selectCard(int cardId)
{
	//buttons[cardId]->ShowWindow(SW_HIDE);
	//buttons[cardId]->EnableWindow(false);
	buttons[cardId]->enableButton(false);

	int newX = _cardPosX + 60;
	int newY = _cardPosY - 120;
	/*int newWidth = 50;
	int newHeight = 100;*/

	//buttons[cardId]->MoveWindow(newX, newY, newWidth, newHeight);
	buttons[cardId]->moveButton(newX, newY);
}
