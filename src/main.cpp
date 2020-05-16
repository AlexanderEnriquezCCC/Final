#include <iostream>

#include "eucher.hpp"

int main()
{
    Eucher * eucher = new Eucher();
    eucher->newPlayer("Alex 1");
    eucher->newPlayer("Alex 2");
    eucher->newPlayer("Alex 3");
    eucher->newPlayer("Alex 4");

    eucher->dealCards();
    eucher->playerHands();
    return 0;
}