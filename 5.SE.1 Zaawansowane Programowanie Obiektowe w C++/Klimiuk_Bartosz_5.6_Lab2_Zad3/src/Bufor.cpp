#include "Bufor.h"
#include <iostream>

Bufor::Bufor()
{
    setTab(10);
    //ctor
}

Bufor::Bufor(int N)
{
    setTab(N);
}

Bufor::~Bufor()
{
    delete [] tab;
    //dtor
}

void Bufor::add(int value)
{
    setFirst(value);
}

int Bufor::getIndex()
{
    return index;
}

int Bufor::getSize()
{
    return n;
}

int Bufor::getTab(int i)
{
    return tab[i];
}

int Bufor::getFirst()
{
    return getIndex();
}

void Bufor::setTab(int N)
{
    if(N>=0)
    {
        n = N;
        tab = new int[N];
        index = 0;
    }
}

void Bufor::setFirst(int value)
{
    tab[index] = value;
    index++;
}

void Bufor::setTab(int pos, int value)
{
    if(pos<n && pos>=0)
    {
        tab[pos] = value;
        if(pos==index)
            index++;
    }
    else
        {
            std::cout<<"Podany index jest niedostepny"<<std::endl;
        }

}

void Bufor::show()
{
    for(int i=0; i<index; i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;
}
