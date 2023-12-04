#include "card.hpp"
#include <iostream>

Card::Card(std::string s, std::string v) : suit(s), value(v) {}

void Card::displayCard() {
    std::cout << value << " of " << suit << std::endl;
}
