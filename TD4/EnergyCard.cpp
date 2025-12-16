#include "EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& energyType) : Card("Energy"), energyType(energyType) {}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Type: " << energyType << std::endl;
}

std::string EnergyCard::getEnergyType() const {
    return energyType;
}