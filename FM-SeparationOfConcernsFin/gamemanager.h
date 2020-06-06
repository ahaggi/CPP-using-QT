#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "gamemenu.h"
#include "player.h"
#include "diceroller.h"

class GameManager
{
public:
    GameManager(GameMenu* m, Player* p);

    void playGame();

private:
    void playRound();

    void playCraps(int& bet);
    void playBlackjack(int& bet);
    void playPowerTwo(int& bet);

    GameMenu* menu;
    Player* player;
    DiceRoller roller;

    int diceMax = 6;
    int diceMin = 1;
};

#endif // GAMEMANAGER_H
