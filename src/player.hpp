#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "cards.hpp"
#include "deck.hpp"
#include <math.h>

class Player
{
    public:
    Player(std::string playerName);
    ~Player();

    void printHand();
    void addToHand(DeckCard * card);
    void clearHand();
    void increaseScore(int incr);
    void setTrumpSuit(std::string trumpSuit);

    int  cardEval(DeckCard * card, std::string trumpSuit);
    float rateHand();

    int getScore();
    std::string getName();
    std::string getColor(std::string suit);

    private:
    std::string m_playerName;
    std::string m_trumpSuit;
    int m_score;

    std::vector<DeckCard *> * m_playerHand;
};


#endif