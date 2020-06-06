#ifndef COLORCHANGERCOLORBLIND_H
#define COLORCHANGERCOLORBLIND_H

#include "colorchangeradt.h"

class colorChangerColorBlind : public colorChangerADT
{
public:
    colorChangerColorBlind();

    std::string randomColor();
};

#endif // COLORCHANGERCOLORBLIND_H
