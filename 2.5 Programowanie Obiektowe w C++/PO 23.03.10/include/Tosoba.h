#ifndef TOSOBA_H
#define TOSOBA_H
#include <string.h>
#include <cstdlib>
#include <iostream>

struct Tdata
{
    int d, m, r;
};

class Tosoba
{
    public:
        Tosoba(); //Konstruktor domyslny
        Tosoba(int dd, int mm, int rr);
        void wczytaj();
        void wyswietl();
        void wyswietl(int rok);
        void info();
        void info(int rok);
        ~Tosoba(); //Destruktor

    private:
        char nazwisko[30];
        std::string imie;
        Tdata dataUr;
};

#endif // TOSOBA_H
