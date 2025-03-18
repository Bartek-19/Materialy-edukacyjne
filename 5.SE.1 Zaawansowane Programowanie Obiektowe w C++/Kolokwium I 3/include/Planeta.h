#ifndef PLANETA_H
#define PLANETA_H
#include <iostream>

using namespace std;

class Planeta
{
    public:
        Planeta(string n, float s, float m, float odl, float obi, float obr, int k, string r);
        string nazwa;
        float srednica;
        float masa;
        float odleglosc;
        float obieg;
        float obrot;
        int ksiezyce;
        string rodzaj;
};

#endif // PLANETA_H
