#include <iostream>

#include "player.h"
#include "gamemanager.h"
#include "gamemenu.h"

using namespace std;

int main()
{
    auto player = new Player(2000);
    auto menu = new GameMenu();

    auto manager = new GameManager(menu,player);

    menu->printGreeting();

    manager->playGame();
}
