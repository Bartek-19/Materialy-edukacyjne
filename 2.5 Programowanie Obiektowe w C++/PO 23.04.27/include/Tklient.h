#ifndef TKLIENT_H
#define TKLIENT_H
#include <string>

using namespace std;

class Tklient
{
    public:
        Tklient();
        void wczytaj();
        void wyswietl();
        virtual ~Tklient();

    protected:
        int NIP;
        string imie, nazwisko;

    private:
};

#endif // TKLIENT_H
