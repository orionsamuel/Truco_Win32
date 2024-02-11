#pragma once
#include <ctime>
#include <random>
#include <string>

#include <vector>
#include <memory>
#include <string>
#include <map>

#include "card.h"
#include "cardView.h"
#include "enums.h"
#include "customButton.h"
#include "resource.h"

class cardController
{
private:
	//std::vector<std::shared_ptr<CString>> cards;
	std::vector<CString> cards;
	//std::map<int, CButton*> buttons;
	std::map<int, customButton*> cardButtons;
	CFrameWnd* _parent;

	CString _playerName;
	int _cardPosX = 100;
	int _cardPosY = 100;
	bool _isVertical = true;
	int _baseId = 0;

	CRect createCard(int posX, int posY) const;
	void enableCards(bool isEnable = true) const;

public:
	cardController() = default;
	cardController(card& c, cardView& cv);
	void createCard(Suit s, Value v);
	explicit cardController(CFrameWnd* parent, std::string playerName, int baseId, int posX, int posY, bool isVertical);
	void createDeck();
	void displayCard();
	card getCard();
	Suit getSuit();
	Value getValue();
	void generateCard();

private:
	card c;
	cardView cv;
	std::mt19937 randomEngine;

	int getRandomNumber(int min, int max);

	int getBaseId();
	void selectCard(int cardId);
};

