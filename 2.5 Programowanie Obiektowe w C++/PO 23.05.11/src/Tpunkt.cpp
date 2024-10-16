#include "Tpunkt.h"

Tpunkt::Tpunkt(float Ax, float Ay)
{
    //ctor
    x = Ax;
    y = Ay;
}

void Tpunkt::ruch(float dx, float dy)
{
    x += dx;
    y += dy;
}

float Tpunkt::getx()
{
    return x;
}

float Tpunkt::gety()
{
    return y;
}

Tpunkt::~Tpunkt()
{
    //dtor
}
