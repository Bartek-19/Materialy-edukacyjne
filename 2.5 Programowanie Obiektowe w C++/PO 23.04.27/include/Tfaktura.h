#ifndef TFAKTURA_H
#define TFAKTURA_H

#include <Tdokument.h>
#include "Ttowar.h"
#include "Tklient.h"

class Tfaktura : public Tdokument
{
    public:
        Tfaktura(Tklient *k, int n);
        void wczytaj();
        void wyswietl();
        float suma();
        virtual ~Tfaktura();

    protected:
        Tklient *klient;
        Ttowar *towary;
        int liczbaTowarow;

    private:
};

#endif // TFAKTURA_H
