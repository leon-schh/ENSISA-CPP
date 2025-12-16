#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "trainer_card.h"
#include <string>
#include <vector>

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;

public:
    Player(const std::string& name);
    ~Player();
    
    void addCardToBench(Card* card);
    void activatePokemonCard(int benchIndex);
    void attachEnergyCard(int benchEnergyIndex, int actionPokemonIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int actionPokemonIndex, int attackIndex, Player& target, int targetActionIndex);
    void useTrainer(int benchIndex);
    
    std::string getPlayerName() const;
    std::vector<PokemonCard*>& getActionCards();
};

#endif