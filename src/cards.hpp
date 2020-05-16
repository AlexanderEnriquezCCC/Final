#ifndef CARDS_HPP
#define CARDS_CPP

#include "deck.hpp"
#include <map>

class Cards : public Deck
{
    public:
    void newDeck() override;
    std::string checkColor(std::string suit);

    private:
    //don't need anything here

};


#endif