#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "player.h"
#include "gametype.h"

class GameMenu
{
public:
    GameMenu();

    void printGreeting();

    void printGameOver(int funds);

    void printPlayerFunds(int funds);

    void printRoll(int d1, int d2);

    void printWin();

    void printLoss();

    bool playNewGame();

    GameType getGameType();

    int getPlayerBet(Player* p);
};

#endif // GAMEMENU_H
