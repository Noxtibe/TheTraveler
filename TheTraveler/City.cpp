#include "City.h"

City::City(char _name, double _x, double _y) : name(_name), x(_x), y(_y) 
{
}

char City::getName() const 
{
    return name;
}

double City::getX() const 
{
    return x;
}

double City::getY() const 
{
    return y;
}