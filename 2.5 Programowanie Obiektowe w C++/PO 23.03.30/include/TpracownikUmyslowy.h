#ifndef TPRACOWNIKUMYSLOWY_H
#define TPRACOWNIKUMYSLOWY_H

#include <Tpracownik.h>


class TpracownikUmyslowy : public Tpracownik
{
    public:
        TpracownikUmyslowy();
        TpracownikUmyslowy(string i, string n, string nFirmy, float w, int p, string s, string d);
        void wczytaj();
        void wyswietl();
        virtual ~TpracownikUmyslowy();

    protected:
        string stanowisko, dzial;

    private:
};

#endif // TPRACOWNIKUMYSLOWY_H
