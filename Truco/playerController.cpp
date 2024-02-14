#include "pch.h"
#include "playerController.h"

playerController::playerController(int positionX, int positionY, CFrameWnd* pParentWnd, UINT nID)
{
	playerId = nID;

	_deckSettings = deckController(positionX, positionY + 50, pParentWnd, nID);
	_playerView = playerView(positionX, positionY, pParentWnd, nID);
}

void playerController::createPlayer(std::string name, bool isCpu)
{
	_player.name = name;
	_player.setPlayerType(isCpu);
}

void playerController::addCard(cardController card)
{
	_deckSettings.addCard(card);
}

void playerController::changeCardSelection(int cardId)
{
	_deckSettings.changeCardSelection(cardId);
}

cardController playerController::dealCard()
{
	return _deckSettings.popCard();
}

std::string playerController::getName() {
	return _player.name;
}

void playerController::displayPlayer() const
{
	_playerView.displayPlayerName(_player);
	_deckSettings.displayDeck();
}

void playerController::enableToSelectCard() const
{
	_deckSettings.enableToSelectCard();
}
