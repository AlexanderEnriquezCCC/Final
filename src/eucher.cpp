#include "eucher.hpp"

Eucher::Eucher()
{
    this->m_playingCards = new Cards();
    this->m_players = new std::map<std::string, Player*>();
    this->m_playingCards->newDeck();
    this->m_playingCards->shuffle();
}

Eucher::~Eucher()
{
    delete this->m_playingCards;
}

void Eucher::newPlayer(std::string Name)
{
    Player * newPlayer = new Player(Name);
}

void Eucher::playerHands()
{
    for (std::map<std::string, Player*>::iterator it = this->m_players->begin(); it != this->m_players->end(); ++it)
    {
        it->second->printHand();
    }
}

void Eucher::rankedHands()
{
    for (std::map<std::string, Player*>::iterator it = this->m_players->begin(); it != this->m_players->end(); ++it)
    {
        std::cout << "[" << it->first << "]" << std::endl;
        std::cout << "Hand Score : " << it->second->rateHand() << std::endl;
    }
}

void Eucher::dealCards()
{
    int cardsDelt = 2;
    for (int i = 0; i < 2; i++)
    {
        if (i == 1) { cardsDelt = 3; }
        for (std::map<std::string, Player*>::iterator it = this->m_players->begin(); it != this->m_players->end(); ++it)
        {
            for (int j = 0; j < cardsDelt; j++)
            {
                it->second->addToHand(this->m_playingCards->nextCard());
            }
        }
    }
}

std::string Eucher::getTrumpSuit()
{
    return this->m_trumpSuit;
}