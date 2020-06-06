#include "player.h"

Player::Player(int initialFunds)
{
    funds = initialFunds;
}

int Player::getFunds()
{
    return funds;
}

void Player::deductFunds(int amount)
{
    if(funds < amount)
    {
        funds = 0;
    }
    else
    {
        funds -= amount;
    }
}

void Player::addFunds(int amount)
{
    if(0 < amount)
    {
        funds += amount;
    }
}
