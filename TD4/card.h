#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
protected:
    std::string cardName;

public:
    Card();
    Card(const std::string& name);
    virtual ~Card() = default;
    virtual void displayInfo() const = 0;
    std::string getCardName() const;
};

#endif