#ifndef EUCHER_HPP
#define EUCHER_HPP

#include "cards.hpp"
#include "player.hpp"

class Eucher
{
    public:
    Eucher();
    ~Eucher();

    void newPlayer(std::string Name);
    void playerHands();
    void dealCards();
    void rankedHands();

    std::string getTrumpSuit();

    private:
    Cards * m_playingCards;
    std::string m_trumpSuit;
    std::map<std::string,Player*> * m_players;
};

#endif