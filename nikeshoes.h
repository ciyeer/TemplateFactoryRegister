#ifndef NIKESHOES_H
#define NIKESHOES_H
#include "shoes.h"
#include <iostream>

class NikeShoes : public Shoes
{
public:
    virtual void show() override
    {
        std::cout << "Just do it" << std::endl;
    }
};

#endif // NIKESHOES_H
