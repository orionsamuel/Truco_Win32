#include "pch.h"
#include "cardController.h"

cardController::cardController(card& c, cardView& cv) : c(c), cv(cv) {}

void cardController::displayCard()
{
	cv.displayCard(c);
}
