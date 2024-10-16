#ifndef TOSOBA_H
#define TOSOBA_H
#include <string>

using namespace std;

class Tosoba
{
    public:
        Tosoba();
        Tosoba(string i, string n);
        void wczytaj();
        void wyswietl();
        virtual ~Tosoba();

    protected:
        string imie, nazwisko;

    private:
};

#endif // TOSOBA_H
