#ifndef TOSOBA2_H
#define TOSOBA2_H
#include <Tdata.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class Tosoba2
{
    public:
        Tosoba2();
        Tosoba2(string naz, string im, Tdata d);
        void wczytaj();
        void wyswietl();
        string GetNazwiskoImie();
        int roznicaWieku(Tosoba2 & partner);
        Tosoba2 dluzszeNazwisko(Tosoba2 &partner);
        virtual ~Tosoba2();

    private:
        string imie, nazwisko, motto;
        Tdata dataUr;
};

#endif // TOSOBA2_H
