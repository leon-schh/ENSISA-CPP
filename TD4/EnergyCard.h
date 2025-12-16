#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "card.h"
#include <string>

class EnergyCard : public Card {
private:
    std::string energyType;

public:
    EnergyCard(const std::string& energyType);
    void displayInfo() const override;
    std::string getEnergyType() const;
};

#endif