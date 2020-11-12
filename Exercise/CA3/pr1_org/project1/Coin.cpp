/*
* Vending Machine Project
* CSE-40477
*
* Coin.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "Coin.h"

Project1::Coin::Coin(CoinType denomination)
    : denomination(denomination)
{
    // TODO: Implement
}

Project1::Coin::CoinType
Project1::Coin::getDenomination() const
{
    // TODO: Implement
    return Coin::COINTYPE_WOODEN_NICKEL;
}

unsigned
Project1::Coin::getValueCents() const
{
    // TODO: Implement
    return 0;
}
