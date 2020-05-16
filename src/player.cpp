#include "player.hpp"

Player::Player(std::string playerName)
{
    this->m_playerName = playerName;
    this->m_playerHand = new std::vector<DeckCard*>();
    this->m_score = 0;
}

Player::~Player()
{
    delete this->m_playerHand;
    //delete this->m_playerName;
    //delete this->m_score;
}

void Player::setTrumpSuit(std::string trumpSuit)
{
    this->m_trumpSuit = trumpSuit;
}

void Player::printHand()
{
    std::cout << this->m_playerName << " score:" << std::endl;
    
    std::string vals;
    std::string suit;
    int point;

    for(int i = 0; i < this->m_playerHand->size(); i++)
    {
        vals = this->m_playerHand->at(i)->points; //i don't understand this error, points should be here when I make do newDeck in cards.cpp
        suit = this->m_playerHand->at(i)->suit;
        std::cout << vals << " of " << suit << "." << std::endl;
    }
    std::cout << "Score: " << this->rateHand() << std::endl;
}

std::string Player::getColor(std::string suit)
{
    if (suit == "Hearts" || suit == "Diamonds") { return "Red"; }
    else { return "Black"; }
}

int Player::cardEval(DeckCard * card, std::string trumpSuit)
{
    std::string suitColor = this->getColor(trumpSuit);

    std::map<std::string, int> cardVal = std::map<std::string, int>();

    cardVal.insert(std::pair<std::string, int>("9",     1));
    cardVal.insert(std::pair<std::string, int>("10",    2));
    cardVal.insert(std::pair<std::string, int>("Jack",  3));
    cardVal.insert(std::pair<std::string, int>("Queen", 4));
    cardVal.insert(std::pair<std::string, int>("King",  5));
    cardVal.insert(std::pair<std::string, int>("Ace",   6));

    if(card->points == "Jack")
    {
        if(card->suit == trumpSuit){return 13;}
        else if(card->suit == suitColor){return 12;}
        else{return cardVal[card->points];}
    }

    else if(card->suit == trumpSuit)
    {
        if (card->points == "9"){ return cardVal[card->points] + 6; }
        else if (card->points == "10"){ return cardVal[card->points] + 6; }
        else if (card->points == "Queen"){ return 9; }
        else if (card->points == "King"){ return 10; }
        else if (card->points == "Ace"){ return 11; }
    }
    else{return cardVal[card->points];}

    return 999;
}

void Player::addToHand(DeckCard* card)
{
    this->m_playerHand->push_back(card);
}

void Player::clearHand()
{
    this->m_playerHand->clear();
}

std::string Player::getName()
{
    return this->m_playerName;
}

void Player::increaseScore(int incr)
{
    this->m_score += incr;
}

int Player::getScore()
{
    return this->m_score;
}

float Player::rateHand()
{
    int pointValue = 0;
    float multiplier = 1.0 / 55.0;
    for (int i = 0; i < this->m_playerHand->size(); i++)
    {
        pointValue += this->cardEval(this->m_playerHand->at(i), this->m_trumpSuit);
    }
    return  roundf(100 * ((float)pointValue * multiplier)) * 0.01;
}