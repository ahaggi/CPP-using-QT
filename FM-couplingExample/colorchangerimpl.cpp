

#include "colorchangerimpl.h"

colorChangerImpl::colorChangerImpl()
{
    srand(time(NULL));
}

std::string colorChangerImpl::randomColor()
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
        newColor = "background-color:green";
        break;
    case 4:
        newColor = "background-color:red";
        break;
    default:
        break;
    }

    return newColor;
}
