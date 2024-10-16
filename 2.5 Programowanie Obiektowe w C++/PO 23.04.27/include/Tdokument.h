#ifndef TDOKUMENT_H
#define TDOKUMENT_H
#include <string>

using namespace std;

class Tdokument
{
    public:
        Tdokument();
        void wczytaj();
        void wyswietl();
        virtual ~Tdokument();

    protected:
        string numer;
        string nazwa;
        struct tData{
            int d, m, r;
        };
        tData dataWystawienia;
    private:
};

#endif // TDOKUMENT_H
