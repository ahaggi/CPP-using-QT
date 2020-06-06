#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player(int initialFunds = 1000);

    int getFunds();

    void deductFunds(int amount);
    void addFunds(int amount);

private:
    int funds;
};

#endif // PLAYER_H
