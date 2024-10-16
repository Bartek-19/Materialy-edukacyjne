#ifndef TPRACOWNIK_H
#define TPRACOWNIK_H

#include <Tosoba.h>


class Tpracownik : public Tosoba
{
    public:
        Tpracownik();
        Tpracownik(string i, string n, string nazwa, float w, int p);
        void wczytaj();
        void wyswietl();
        float przychod();
        virtual ~Tpracownik();

    protected:
        string firma;
        float wyplata;
        int premia;

    private:
};

#endif // TPRACOWNIK_H
