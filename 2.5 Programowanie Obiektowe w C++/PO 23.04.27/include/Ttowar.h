#ifndef TTOWAR_H
#define TTOWAR_H
#include <string>

using namespace std;

class Ttowar
{
    public:
        Ttowar();
        void wczytaj();
        void wyswietl();
        float oblicz();
        virtual ~Ttowar();

    protected:
        string kod;
        string nazwa;
        float cena;
        int ilosc;
    private:
};

#endif // TTOWAR_H
