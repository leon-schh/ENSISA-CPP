#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include "card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card {
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int currentHP;
    std::vector<std::tuple<int, int, std::string, int>> attacks;

public:
    PokemonCard(const std::string& pokemonName, const std::string& pokemonType, 
                const std::string& familyName, int evolutionLevel, int maxHP,
                int attack1Cost, const std::string& attack1Description, int attack1Damage,
                int attack2Cost, const std::string& attack2Description, int attack2Damage);
    
    void displayInfo() const override;
    std::string getPokemonType() const;
    std::string getFamilyName() const;
    int getEvolutionLevel() const;
    int getMaxHP() const;
    int getCurrentHP() const;
    void setCurrentHP(int hp);
    std::vector<std::tuple<int, int, std::string, int>> getAttacks() const;
    void useAttack(int attackIndex, PokemonCard& target);
    void addEnergy(int attackIndex);
};

#endif