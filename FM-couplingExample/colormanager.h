#ifndef COLORMANAGER_H
#define COLORMANAGER_H

#include "colorchanger.h"

class colorManager
{
public:
    colorManager();

    std::string getRandomColor();

private:
    colorChanger * cChanger;
};

#endif // COLORMANAGER_H
