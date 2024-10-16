#ifndef TDOMOWNIK_H
#define TDOMOWNIK_H
#include <string>

using namespace std;

class Tdomownik
{
    public:
        Tdomownik(string N, string S);
        void wyswietl();
        virtual ~Tdomownik();
        friend void sasiad(Tdomownik &D);
        friend class Tsasiad;

    private:
        string nazwa, sekret;
        static int kod;
        static void setKod();
        static int getKod();
};

#endif // TDOMOWNIK_H
