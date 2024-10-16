#include <iostream>
#include "Tdokument.h"
#include "Tfaktura.h"
#include "Ttowar.h"
#include "Tklient.h"

using namespace std;

int main()
{
    Tklient klient;
    int x;

    cout<<"> Wczytywanie danych klienta"<<endl;
    klient.wczytaj();
    cout<<"> Podaj ilosc zakupionych przedmiotow:  ";
    cin>>x;

    Tfaktura faktura(&klient, x);

    cout<<endl;
    faktura.wczytaj();

    cout<<endl;
    faktura.wyswietl();

    return 0;
}
