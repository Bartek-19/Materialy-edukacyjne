#ifndef TPRACOWNIK_H
#define TPRACOWNIK_H

struct tData {
    int d, m, r;
};

class Tpracownik
{
    private:
        char imie[20], nazwisko[30];
        float stawka;
        int godziny;
        tData zatr;
    public:
        void wczytaj();
        float wyplata();
        void wyswietl();
};

#endif // TPRACOWNIK_H
