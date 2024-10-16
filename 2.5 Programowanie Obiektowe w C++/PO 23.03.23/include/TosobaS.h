#ifndef TOSOBAS_H
#define TOSOBAS_H
#include <string>
#include <iostream>

using namespace std;

const int DL = 20;

class TosobaS
{
    private:
        static int liczbaObiektow;//pole statyczne
        static string kraj;
    protected:
        char nazwisko[DL], imie[DL];
        int wiek;
    public:
        TosobaS(); //Konieczna redefinicja pol
        TosobaS(TosobaS &oryginal);
        TosobaS(char *naz, char *im, int w);
        void podajDane();
        void wyswietl();
        ~TosobaS();
        static int ile();//metoda statyczna
        static string getKraj();
};

#endif // TOSOBAS_H
