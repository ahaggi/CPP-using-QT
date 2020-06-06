#ifndef DICEROLLER_H
#define DICEROLLER_H


class DiceRoller
{
public:
    DiceRoller();
    void init(int min, int max);

    void rollDice(int* dice1, int* dice2);
    void rollDice(int& dice1, int& dice2);

private:
    int min;
    int max;
};

#endif // DICEROLLER_H
