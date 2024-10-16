#ifndef TSTUDENT_H
#define TSTUDENT_H

#include <Tosoba.h>
#include <cstdlib>


class Tstudent : public Tosoba
{
    public:
        Tstudent();
        Tstudent(string i, string n, string u, int lo);
        void wczytaj();
        void wczytajOceny();
        void wyswietl();
        float sredniaOcen();
        bool czyZdane();
        virtual ~Tstudent();

    protected:
        string uczelnia;
        int liczbaOcen;
        float *oceny;
    private:
};

#endif // TSTUDENT_H
