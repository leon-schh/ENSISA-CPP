#include "card.h"

Card::Card(const std::string& name) : cardName(name) {}

std::string Card::getCardName() const {
    return cardName;
}