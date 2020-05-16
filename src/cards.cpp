#include "cards.hpp"

void Cards::newDeck()
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

std::string Cards::checkColor(std::string suit)
{
    if(suit=="Hearts" || suit == "Diamonds"){return "Red";}
    else{return "Black";}
}