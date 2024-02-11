#include "cardController.h"
#include "pch.h"

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

void cardController::enableCards(bool isEnable) const
{
	for (auto& card : cardButtons) {
		card.second->enableButton(isEnable);

		if (!isEnable)
		{
			card.second->ModifyStyle(0, BS_BITMAP);
			card.second->SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CARD_BACKGROUND)));
		}
		else {
			card.second->SetBitmap(NULL);
			card.second->ModifyStyle(BS_BITMAP, 0);
		}
	}
}


cardController::cardController(card& c, cardView& cv) : c(c), cv(cv), randomEngine(std::random_device{}()) {}

void cardController::createCard(Suit s, Value v)
{
	try {
		c.suit = s;
		c.value = v;
	}
	catch (const std::exception& e) {
		std::cerr << "Error creating card: " << e.what() << std::endl;
	}
}

void cardController::displayCard()
{
	try {
		cv.displayCard(c);
	}
	catch (const std::exception& e) {
		std::cerr << "Error displaying card: " << e.what() << std::endl;
	}
}

card cardController::getCard()
{
	return c;
}

Suit cardController::getSuit()
{
	try {
		std::uniform_int_distribution<int> distribution(1, static_cast<int>(Suit::DIAMONDS));
		return static_cast<Suit>(distribution(randomEngine));
	}
	catch (const std::exception& e) {
		std::cerr << "Error getting suit: " << e.what() << std::endl;
		return Suit::DIAMONDS;
	}
}

Value cardController::getValue()
{
	try {
		std::uniform_int_distribution<int> distribution(1, static_cast<int>(Value::KING));
		return static_cast<Value>(distribution(randomEngine));
	}
	catch (const std::exception& e) {
		std::cerr << "Error getting value: " << e.what() << std::endl;
		return Value::KING;
	}
}

void cardController::generateCard() {
	c.value = static_cast<Value>(getRandomNumber(1, static_cast<int>(Value::KING)));
	c.suit = static_cast<Suit>(getRandomNumber(1, static_cast<int>(Suit::DIAMONDS)));
}

int cardController::cardController::getRandomNumber(int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(randomEngine);
}
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
		cardButtons.insert(std::make_pair(id, newButton));

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
	if (cardButtons[cardId]->getSelectedStatus()) {
		cardButtons[cardId]->setSelectedStatus(false);
		cardButtons[cardId]->reloadButtonPosition();
		enableCards(true);
	}
	else {
		//buttons[cardId]->ShowWindow(SW_HIDE);
		//buttons[cardId]->EnableWindow(false);
		enableCards(false);
		cardButtons[cardId]->enableButton(true);
		cardButtons[cardId]->setSelectedStatus(true);

		cardButtons[cardId]->SetBitmap(NULL);
		cardButtons[cardId]->ModifyStyle(BS_BITMAP, 0);

		int newX = _cardPosX + 60;
		int newY = _cardPosY - 120;
		/*int newWidth = 50;
		int newHeight = 100;*/

		//buttons[cardId]->MoveWindow(newX, newY, newWidth, newHeight);
		cardButtons[cardId]->moveButton(newX, newY);
	}
}
