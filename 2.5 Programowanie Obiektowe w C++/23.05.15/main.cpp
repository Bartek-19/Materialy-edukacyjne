#include <iostream>

using namespace std;

void zad17()
{
    int n, wynik;

    do{
        cout<<"Podaj liczbê nieujemna:  ";
        cin>>n;
    } while(n < 0);

    do{
        wynik = 0;

        while(n > 0)
        {
            wynik += n%10;
            n/=10;
        }

        cout<<wynik<<endl;

        if(wynik > 9)
            n = wynik;

    } while(wynik > 9);

    cout<<"Koncowa suma cyfr = "<<wynik<<endl;
}

void zad18()
{
    int n, iMin, iMaks;
    int *tab;

    do{
        cout<<"Podaj ilosc elementow:  ";
        cin>>n;
    } while(n <= 0);

    tab = new int[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Podaj element do tablicy:  ";
        cin>>tab[i];
        if(i==0)
        {
            iMin = i;
            iMaks = i;
        }
        else
        {
            if(tab[i]<tab[iMin])
                iMin = i;
            if(tab[i]>tab[iMaks])
                iMaks = i;
        }
    }

    cout<<"Najminiejszy element to element "<<iMin<<" i wynosi: "<<tab[iMin]<<endl;
}

int main()
{
    int zadanie;

    while(zadanie != 0)
    {
        do{
        cout<<"Wybierz zadanie (16 - 19):  ";
        cin>>zadanie;
        } while((zadanie < 16 || zadanie > 19) && zadanie!=0);

        cout<<endl;

        switch(zadanie)
        {
        case 16:
        case 18:
        case 19:
            cout<<"Zadanie jeszcze niegotowe"<<endl;
            break;
        case 17:
            zad17();
            break;
        default:
            cout<<"Koniec programu"<<endl;
        }
        cout<<endl;
    }

    return 0;
}
