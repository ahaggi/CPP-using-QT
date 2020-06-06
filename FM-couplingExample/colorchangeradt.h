#ifndef COLORCHANGERADT_H
#define COLORCHANGERADT_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

class colorChangerADT
{
public:
    virtual std::string randomColor() = 0;
};

#endif // COLORCHANGERADT_H
