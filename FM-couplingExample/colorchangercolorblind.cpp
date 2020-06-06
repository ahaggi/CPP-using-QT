#include <time.h>

#include "colorchangercolorblind.h"

colorChangerColorBlind::colorChangerColorBlind()
{
    srand(time(NULL));
}

std::string colorChangerColorBlind::randomColor()
{
    int color = rand() % 4 + 1;

    std::string newColor = "background-color:none";

    switch (color) {
    case 1:
        newColor = "background-color:grey";
        break;
    case 2:
        newColor = "background-color:blue";
        break;
    case 3:
        newColor = "background-color:purple";
        break;
    case 4:
        newColor = "background-color:orange";
        break;
    default:
        break;
    }

    return newColor;
}
