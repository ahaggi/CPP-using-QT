#include <iostream>
#include "gamemenu.h"

using namespace std;

GameMenu::GameMenu()
{

}

void GameMenu::printGreeting()
{
    cout << "Welcome to the fantastic C++ interactive casino!" << endl;
}

void GameMenu::printGameOver(int funds)
{
    if(funds == 0)
    {
        cout << "Sorry, you cannot play without any money" << endl;
    }
    else
    {
        cout << "Good bye, you have " << funds << " left after your visit" << endl;
    }
}

void GameMenu::printPlayerFunds(int funds)
{
    cout << "You have " << funds << " available to bet with" << endl;
}

void GameMenu::printRoll(int d1, int d2)
{
    cout << "Rolled " << d1 << " and " << d2 << endl;
}

void GameMenu::printWin()
{
    cout << "You Won!" << endl;
}

void GameMenu::printLoss()
{
    cout << "You lost" << endl;
}

bool GameMenu::playNewGame()
{
    int input;
    cout << "Would you like to play a new game? 1=yes 2=no" << endl;
    cin >> input;

    if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    return input == 1;

}

GameType GameMenu::getGameType()
{
    GameType choice = NONE;
    int input;

    cout << "What game would you like to play? 1=Craps 2=Blackjack dice 3=Power of two!" << std::endl;
    cin >> input;

    if(!cin)
    {
        cout << "Sorry, that is not a recognized game." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        if(input < 4 && 0 < input)
        {
            choice = static_cast<GameType>(input);
        }
    }

    return choice;
}

int GameMenu::getPlayerBet(Player* p)
{
    cout << "How much would you like to bet?" << endl;

    int betAmount;
    cin >> betAmount;

    if(!cin)
    {
        betAmount = -1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(p->getFunds() < betAmount)
    {
        betAmount = -1;
    }
    else if(betAmount < 0)
    {
        betAmount = -1;
    }

    if(betAmount == -1)
    {
        cout << "Please bet a valid amount" << endl;
    }

    return betAmount;
}
