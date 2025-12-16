#include "player.h"
#include <iostream>

Player::Player(const std::string& name) : playerName(name) {}

Player::~Player() {
    for (auto card : benchCards) {
        delete card;
    }
    for (auto pokemon : actionCards) {
        delete pokemon;
    }
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < static_cast<int>(benchCards.size())) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
        if (pokemon) {
            actionCards.push_back(pokemon);
            std::cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << std::endl;
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::attachEnergyCard(int benchEnergyIndex, int actionPokemonIndex) {
    if (benchEnergyIndex >= 0 && benchEnergyIndex < static_cast<int>(benchCards.size()) &&
        actionPokemonIndex >= 0 && actionPokemonIndex < static_cast<int>(actionCards.size())) {
        
        EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchEnergyIndex]);
        if (energy) {
            std::cout << playerName << " is attaching Energy Card of type " 
                      << energy->getEnergyType() << " to the Pokemon " 
                      << actionCards[actionPokemonIndex]->getCardName() << std::endl;
            
            actionCards[actionPokemonIndex]->addEnergy(0);
            actionCards[actionPokemonIndex]->addEnergy(1);
            
            benchCards.erase(benchCards.begin() + benchEnergyIndex);
        }
    }
}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << ":" << std::endl;
    for (size_t i = 0; i < benchCards.size(); ++i) {
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << ":" << std::endl;
    for (size_t i = 0; i < actionCards.size(); ++i) {
        actionCards[i]->displayInfo();
    }
}

void Player::attack(int actionPokemonIndex, int attackIndex, Player& target, int targetActionIndex) {
    if (actionPokemonIndex >= 0 && actionPokemonIndex < static_cast<int>(actionCards.size()) &&
        targetActionIndex >= 0 && targetActionIndex < static_cast<int>(target.actionCards.size())) {
        
        actionCards[actionPokemonIndex]->useAttack(attackIndex, *target.actionCards[targetActionIndex]);
    }
}

void Player::useTrainer(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < static_cast<int>(benchCards.size())) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);
        if (trainer && trainer->getTrainerEffect() == "heal all your action pokemon") {
            std::cout << playerName << " is using the Trainer Card to \"" << trainer->getTrainerEffect() << "\"" << std::endl;
            
            for (auto pokemon : actionCards) {
                pokemon->setCurrentHP(pokemon->getMaxHP());
            }
            
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

std::string Player::getPlayerName() const {
    return playerName;
}

std::vector<PokemonCard*>& Player::getActionCards() {
    return actionCards;
}