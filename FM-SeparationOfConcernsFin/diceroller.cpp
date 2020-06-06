#include <stdlib.h>
#include <time.h>

#include "diceroller.h"

DiceRoller::DiceRoller()
{
    srand(time(NULL));
}

void DiceRoller::init(int min, int max)
{
    this->min = min;
    this->max = max;
}

void DiceRoller::rollDice(int* dice1, int* dice2)
{
    *dice1 = rand()%max + min;
    *dice2 = rand()%max + min;
}

void DiceRoller::rollDice(int &dice1, int &dice2)
{
    dice1 = rand()%max + min;
    dice2 = rand()%max + min;
}
