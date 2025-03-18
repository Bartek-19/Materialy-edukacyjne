#include "MaxBufor.h"
#include <iostream>

MaxBufor::MaxBufor()
{
    //ctor
}

MaxBufor::MaxBufor(int N)
{
    setTab(N);
}

MaxBufor::~MaxBufor()
{
    //dtor
}

double MaxBufor::calculate()
{
    int maxValue = getTab(0);
    for(int i=1; i<getIndex(); i++)
        maxValue = ( maxValue<getTab(i) ) ? getTab(i) : maxValue;

    return (double)maxValue;
}

void MaxBufor::add(int value)
{
    if(getFirst()<getSize())
        setFirst(value);
    else
        std::cout<<"Brak miejsca w buforze"<<std::endl;
}
