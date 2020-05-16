#include <iostream>
#include <math.h>
#include <gtest/gtest.h>
#include "../src/cards.hpp"
#include "../src/deck.hpp"
#include "../src/eucher.hpp"
#include "../src/player.hpp"

TEST(HANDRANK, rank)
{
    Player * player1 = new Player("Walter");
    player1->setTrumpSuit("Spades");
    player1->addToHand(new DeckCard("Jack", "Spades"));
    player1->addToHand(new DeckCard("Jack", "Clubs"));
    player1->addToHand(new DeckCard("Ace", "Spades"));
    player1->addToHand(new DeckCard("King", "Spades"));
    player1->addToHand(new DeckCard("Queen", "Spades"));
    ASSERT_EQ(1, player1->rateHand());
}

TEST(HANDRANK2, rank)
{
    Player * player1 = new Player("Walter");
    player1->setTrumpSuit("Spades");
    player1->addToHand(new DeckCard("10", "Hearts"));
    player1->addToHand(new DeckCard("10", "Diamonds"));
    player1->addToHand(new DeckCard("9", "Diamonds"));
    player1->addToHand(new DeckCard("9", "Hearts"));
    player1->addToHand(new DeckCard("9", "Clubs"));
    ASSERT_EQ(13, (int)((player1->rateHand()) * 100));
}

TEST(NOTEQUAL, notEqual)
{   
    Deck * deck = new Deck();
    deck->shuffle();

    DeckCard * card1 = deck->nextCard();
    DeckCard * card2 = deck->nextCard();

    ASSERT_FALSE((card1->points == card2->points)&&(card2->suit == card2->suit));
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}