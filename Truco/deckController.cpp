#include<iostream>

#include "deckController.h"
#include "pch.h"

void deckController::addCard(cardController newCard)
{
	try {
        deckCards.baseCards.push_back(std::make_shared<card>(newCard.getCard()));
    } catch (const std::bad_alloc& e) {
        std::cerr << "Error adding card to deck: " << e.what() << std::endl;
    }
}

cardController deckController::popCard()
{
    try {
        if (!deckCards.baseCards.empty()) {
            std::shared_ptr<card> card = deckCards.baseCards.back();
            deckCards.baseCards.pop_back();

            cardController cc;
            cc.createCard(card->suit, card->value);

            return cc;
        }
        else {
            throw std::out_of_range("Deck is empty");
        }
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error popping card from deck: " << e.what() << std::endl;
        return cardController();
    }
}