#include "trainer_card.h"
#include <iostream>

TrainerCard::TrainerCard(const std::string& trainerName, const std::string& effect) 
    : Card(trainerName), trainerEffect(effect) {}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << std::endl;
}

std::string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}