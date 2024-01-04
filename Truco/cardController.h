#pragma once
#include "card.h"
#include "cardView.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

#include "customButton.h"

class cardController
{
private:
	//std::vector<std::shared_ptr<CString>> cards;
	std::vector<CString> cards;
	//std::map<int, CButton*> buttons;
	std::map<int, customButton*> buttons;
	CFrameWnd* _parent;

	CString _playerName;
	int _cardPosX = 100;
	int _cardPosY = 100;
	bool _isVertical = true;
	int _baseId = 0;

	CRect createCard(int posX, int posY) const;

public:
	cardController() = default;
	explicit cardController(CFrameWnd* parent, std::string playerName, int baseId, int posX, int posY, bool isVertical);
	void createDeck();
	void displayCard();

	int getBaseId();
	void selectCard(int cardId);
};

