#include "colormanager.h"

colorManager::colorManager() :
    cChanger(new colorChanger())
{

}

std::string colorManager::getRandomColor()
{
    return cChanger->randomColor();
}
