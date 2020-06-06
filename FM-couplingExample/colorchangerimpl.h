#ifndef COLORCHANGERIMPL_H
#define COLORCHANGERIMPL_H


#include "colorchangeradt.h"

class colorChangerImpl : public colorChangerADT
{
public:
    colorChangerImpl();

    std::string randomColor();
};

#endif // COLORCHANGERIMPL_H
