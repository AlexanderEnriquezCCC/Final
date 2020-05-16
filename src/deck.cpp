#include "deck.hpp"

DeckCard::DeckCard(std::string points, std::string suit)
{
    this->points = points;
    this->suit = suit;
    this->pointVal = 0;
    this->setColor();
}

void DeckCard::setColor()
{
    if (this->suit == "Hearts" || this->suit == "Diamonds")
    {
        this->color = "Red";
    }
    else if (this->suit == "Clubs" || this->suit == "Spades")
    {
        this->color = "Black";
    }
}

Deck::Deck()
{
    this->m_deck = new std::vector<DeckCard*>();
    this->m_discard = new std::stack<DeckCard*>();
}

Deck::~Deck()
{
    delete m_deck;
    delete m_discard;
}

void Deck::newDeck()
{
    this->m_deck->push_back(new DeckCard("2", "H"));
    this->m_deck->push_back(new DeckCard("3", "H"));
    this->m_deck->push_back(new DeckCard("4", "H"));
    this->m_deck->push_back(new DeckCard("5", "H"));
    this->m_deck->push_back(new DeckCard("6", "H"));
    this->m_deck->push_back(new DeckCard("7", "H"));
    this->m_deck->push_back(new DeckCard("8", "H"));
    this->m_deck->push_back(new DeckCard("9", "H"));
    this->m_deck->push_back(new DeckCard("10","H"));
    this->m_deck->push_back(new DeckCard("Jack", "H"));
    this->m_deck->push_back(new DeckCard("Queen","H"));
    this->m_deck->push_back(new DeckCard("King", "H"));
    this->m_deck->push_back(new DeckCard("Ace",  "H"));

    this->m_deck->push_back(new DeckCard("2", "D"));
    this->m_deck->push_back(new DeckCard("3", "D"));
    this->m_deck->push_back(new DeckCard("4", "D"));
    this->m_deck->push_back(new DeckCard("5", "D"));
    this->m_deck->push_back(new DeckCard("6", "D"));
    this->m_deck->push_back(new DeckCard("7", "D"));
    this->m_deck->push_back(new DeckCard("8", "D"));
    this->m_deck->push_back(new DeckCard("9", "D"));
    this->m_deck->push_back(new DeckCard("10","D"));
    this->m_deck->push_back(new DeckCard("Jack", "D"));
    this->m_deck->push_back(new DeckCard("Queen","D"));
    this->m_deck->push_back(new DeckCard("King", "D"));
    this->m_deck->push_back(new DeckCard("Ace",  "D"));

    this->m_deck->push_back(new DeckCard("2", "S"));
    this->m_deck->push_back(new DeckCard("3", "S"));
    this->m_deck->push_back(new DeckCard("4", "S"));
    this->m_deck->push_back(new DeckCard("5", "S"));
    this->m_deck->push_back(new DeckCard("6", "S"));
    this->m_deck->push_back(new DeckCard("7", "S"));
    this->m_deck->push_back(new DeckCard("8", "S"));
    this->m_deck->push_back(new DeckCard("9", "S"));
    this->m_deck->push_back(new DeckCard("10","S"));
    this->m_deck->push_back(new DeckCard("Jack", "S"));
    this->m_deck->push_back(new DeckCard("Queen","S"));
    this->m_deck->push_back(new DeckCard("King", "S"));
    this->m_deck->push_back(new DeckCard("Ace",  "S"));

    this->m_deck->push_back(new DeckCard("2", "C"));
    this->m_deck->push_back(new DeckCard("3", "C"));
    this->m_deck->push_back(new DeckCard("4", "C"));
    this->m_deck->push_back(new DeckCard("5", "C"));
    this->m_deck->push_back(new DeckCard("6", "C"));
    this->m_deck->push_back(new DeckCard("7", "C"));
    this->m_deck->push_back(new DeckCard("8", "C"));
    this->m_deck->push_back(new DeckCard("9", "C"));
    this->m_deck->push_back(new DeckCard("10","C"));
    this->m_deck->push_back(new DeckCard("Jack", "C"));
    this->m_deck->push_back(new DeckCard("Queen","C"));
    this->m_deck->push_back(new DeckCard("King", "C"));
    this->m_deck->push_back(new DeckCard("Ace",  "C"));
}

void Deck::replay()
{
    this->m_deck->clear();
    this->newDeck();
}

void Deck::add()
{
    this->m_deck->push_back(new DeckCard("Joker",  "J1"));
    this->m_deck->push_back(new DeckCard("Joker",  "J2"));
}

void Deck::remove()
{
    int jokers = 2;
    int i = 0;

    while(jokers != 0)
    {
        if(this->m_deck->at(i)->points=="Joker")
        {
            this->m_deck->erase(this->m_deck->begin() + i);
            jokers--;
        }
        else {i++;}
    }
}

void Deck::shuffle()
{
    std::shuffle(this->m_deck->begin(),this->m_deck->end(),std::random_device());
}

DeckCard * Deck::topCard()
{
    DeckCard * c = this->m_deck->back();
}

DeckCard * Deck::nextCard()
{
    DeckCard * c = this->m_deck->back();
    this->m_deck->pop_back();
    return c;
}

void Deck::addtoDiscard(DeckCard * card)
{
    this->m_discard->push(card);
}

int Deck::getRemainingCards()
{
    return this->m_deck->size();
}