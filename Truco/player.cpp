#include "pch.h"
#include "player.h"
#include <iostream>

std::string player::getName()
{
    return name;
}

void player::setName(std::string name) const
{
    this->name = name;
}

void player::drawcard(std::shared_ptr<card> card)
{
    cardList.addCard(card);
}

void player::showCard() const
{
    cardList.showCard();
}
