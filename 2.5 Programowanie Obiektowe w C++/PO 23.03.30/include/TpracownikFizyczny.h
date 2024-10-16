#ifndef TPRACOWNIKFIZYCZNY_H
#define TPRACOWNIKFIZYCZNY_H

#include <Tpracownik.h>


class TpracownikFizyczny : public Tpracownik
{
    public:
        TpracownikFizyczny();
        TpracownikFizyczny(string i, string n, string nFirmy, float w, int p, string s, string nBrygady);
        void wczytaj();
        void wyswietl();
        virtual ~TpracownikFizyczny();

    protected:
        string stanowisko;
        string nazwaBrygady;

    private:
};

#endif // TPRACOWNIKFIZYCZNY_H
