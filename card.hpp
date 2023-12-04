#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(std::string s, std::string v);
    void displayCard();

private:
    std::string suit;
    std::string value;
};

#endif // CARD_H