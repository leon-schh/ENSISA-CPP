#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const std::string& pokemonName, const std::string& pokemonType, 
                        const std::string& familyName, int evolutionLevel, int maxHP,
                        int attack1Cost, const std::string& attack1Description, int attack1Damage,
                        int attack2Cost, const std::string& attack2Description, int attack2Damage)
    : Card(pokemonName), pokemonType(pokemonType), familyName(familyName), 
      evolutionLevel(evolutionLevel), maxHP(maxHP), currentHP(maxHP) {
    
    attacks.push_back(std::make_tuple(attack1Cost, 0, attack1Description, attack1Damage));
    attacks.push_back(std::make_tuple(attack2Cost, 0, attack2Description, attack2Damage));
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType 
              << ", Evolution Level: " << evolutionLevel << " of the family \"" 
              << familyName << "\", HP: " << currentHP << std::endl;
    
    std::cout << "Attacks:" << std::endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        std::cout << "Attack #" << i << ":" << std::endl;
        std::cout << "Attack cost: " << std::get<0>(attacks[i]) << std::endl;
        std::cout << "Attack current energy storage: " << std::get<1>(attacks[i]) << std::endl;
        std::cout << "Attack description: " << std::get<2>(attacks[i]) << std::endl;
        std::cout << "Attack damage: " << std::get<3>(attacks[i]) << std::endl;
    }
}

std::string PokemonCard::getPokemonType() const {
    return pokemonType;
}

std::string PokemonCard::getFamilyName() const {
    return familyName;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

int PokemonCard::getCurrentHP() const {
    return currentHP;
}

void PokemonCard::setCurrentHP(int hp) {
    currentHP = hp;
}

std::vector<std::tuple<int, int, std::string, int>> PokemonCard::getAttacks() const {
    return attacks;
}

void PokemonCard::useAttack(int attackIndex, PokemonCard& target) {
    if (attackIndex >= static_cast<int>(attacks.size())) {
        std::cout << "Only " << attacks.size() << " attacks exist." << std::endl;
        return;
    }
    
    int attackCost = std::get<0>(attacks[attackIndex]);
    int currentEnergy = std::get<1>(attacks[attackIndex]);
    
    if (currentEnergy < attackCost) {
        std::cout << "Not enough energy for this attack!" << std::endl;
        return;
    }
    
    std::get<1>(attacks[attackIndex]) = currentEnergy - attackCost;
    
    int damage = std::get<3>(attacks[attackIndex]);
    int targetNewHP = target.getCurrentHP() - damage;
    target.setCurrentHP(targetNewHP);
    
    std::string attackDesc = std::get<2>(attacks[attackIndex]);
    std::cout << cardName << " attacking " << target.getCardName() << " with the Pokemon " 
              << cardName << " with its attack: " << attackDesc << std::endl;
    std::cout << "Reducing " << damage << " from " << target.getCardName() << "'s Pokemon's HP" << std::endl;
    
    if (target.getCurrentHP() > 0) {
        std::cout << "Pokemon " << target.getCardName() << " is still alive" << std::endl;
    }
}

void PokemonCard::addEnergy(int attackIndex) {
    if (attackIndex >= 0 && attackIndex < static_cast<int>(attacks.size())) {
        std::get<1>(attacks[attackIndex]) += 1;
    }
}