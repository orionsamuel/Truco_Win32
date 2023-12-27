#include "pch.h"
#include "player.h"
#include <iostream>

void player::drawcard(std::shared_ptr<card> card)
{
    cardList.addCard(card);
}

void player::showCard() const
{
    cardList.showCard();
}
