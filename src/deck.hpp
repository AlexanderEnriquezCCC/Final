#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <random>

class Deck
{
    public:
    Deck();
    ~Deck();
    //this class should be inherited
    virtual void newDeck();
    void shuffle();
    void addtoDiscard(DeckCard * card);
    void discardNext();
    void add(); //will add joker cards
    void remove(); //will remove joker cards
    void replay();

    int getRemainingCards();

    DeckCard * topCard();
    DeckCard * nextCard();

    protected:
    std::vector<DeckCard*> * m_deck;
    std::stack<DeckCard*> * m_discard;
};

struct DeckCard
{
    DeckCard(std::string points, std::string suit);

    void setColor();

    int pointVal;
    std::string points;
    std::string suit;
    std::string color;
};

#endif