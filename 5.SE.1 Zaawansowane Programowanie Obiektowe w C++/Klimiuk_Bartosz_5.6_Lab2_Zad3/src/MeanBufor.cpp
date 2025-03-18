#include "MeanBufor.h"
#include "Bufor.h"

MeanBufor::MeanBufor()
{

}

MeanBufor::MeanBufor(int N)
{
    setTab(N);
}

MeanBufor::~MeanBufor()
{

}

double MeanBufor::calculate()
{
    double result = 0;

    for(int i=0; i<getFirst(); i++)
    {
        result += (double)getTab(i);
    }

    if(getFirst()!=0)
        result /= getFirst();

    return result;
}
