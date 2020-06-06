#include "gamemanager.h"

GameManager::GameManager(GameMenu* m, Player* p) : roller()
{
    menu = m;
    player = p;

    diceMin = 1;
    diceMax = 6;
    roller.init(diceMin,diceMax);
}

void GameManager::playGame()
{
    playRound();

    do{
        playRound();
    }while(menu->playNewGame() && player->getFunds() > 0);

    menu->printGameOver(player->getFunds());
}

void GameManager::playRound()
{
    menu->printPlayerFunds(player->getFunds());
    GameType game = menu->getGameType();

    while(game == NONE)
    {
        game = menu->getGameType();
    }

    int bet = menu->getPlayerBet(player);
    while(bet == -1)
    {
        bet = menu->getPlayerBet(player);
    }

    player->deductFunds(bet);

    switch (game) {
    case CRAPS:
        playCraps(bet);
        break;
    case BLACKJACK_DICE:
        playBlackjack(bet);
        break;
    case POWER_OF_TWO:
        playPowerTwo(bet);
        break;
    default:
        break;
    }
}

void GameManager::playCraps(int& bet)
{
    int dice1, dice2;
    roller.rollDice(dice1, dice2);

    int sum = dice1 + dice2;
    menu->printRoll(dice1, dice2);

    if(sum == 11 || sum == 7)
    {
        menu->printWin();
        player->addFunds(bet*2);
    }
    else
    {
        menu->printLoss();
    }

}

void GameManager::playBlackjack(int& bet)
{
    //TODO
}

void GameManager::playPowerTwo(int& bet)
{
    int dice1, dice2;
    roller.rollDice(dice1,dice2);

    int sum = (dice1 + dice2);
    menu->printRoll(dice1,dice2);

    if(!((sum-1) & sum))
    {
        menu->printWin();
        player->addFunds(bet*2);
    }
    else
    {
        menu->printLoss();
    }
}
