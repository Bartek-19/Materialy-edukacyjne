#include "Ttime.h"

Ttime::Ttime(int g, int m)
{
    //ctor
    godziny = g;
    minuty = m;
    //godziny += minuty/60;
    //minuty = minuty%60;
}

Ttime Ttime::operator+(Ttime T)
{
    Ttime wynik(0, 0);

    wynik.godziny = this->godziny + T.godziny;
    wynik.minuty = this->minuty + T.minuty;

    wynik.godziny += wynik.minuty/60;
    wynik.minuty = wynik.minuty%60;

    return wynik;
}

Ttime Ttime::operator-(Ttime T)
{
    Ttime wynik(0, 0);

    wynik.godziny = this->godziny - T.godziny;
    wynik.minuty = this->minuty - T.minuty;

    if(wynik.minuty < 0)
    {
        wynik.godziny -= wynik.minuty / 60;
        wynik.godziny--;
        wynik.minuty = wynik.minuty%60;
    }

    if(wynik.godziny < 0)
    {
        wynik.godziny = 0;
        wynik.minuty = 0;
    }

    return wynik;
}

int Ttime::getHours()
{
    return godziny;
}

int Ttime::getMinutes()
{
    return minuty;
}

void Ttime::changeTime(int H, int M)
{
    godziny = H;
    minuty = M;
}

Ttime::~Ttime()
{
    //dtor
}
