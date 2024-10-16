#ifndef IFIGURA_H
#define IFIGURA_H
#include <string>

using namespace std;

class Ifigura
{
    public:
        Ifigura();
        virtual ~Ifigura();
        virtual void info();
        virtual void rysuj();
        virtual float pole();
        virtual float obwod();
        virtual void wyswietl();

    protected:
        string nazwa;
        float OBW, P;
};

#endif // IFIGURA_H
