#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
    int kolumny, wiersze, n, m, i, j, nrMetody;
    char uzycStockowej;
    double wspolczynnik;

    cout<<"1. Metoda eliminacji podstawowej Gaussa"<<endl;
    cout<<"2. Metoda eliminacji z wyborem elementu maksymalnego"<<endl;
    do {
        cout<<"Podaj numer metody:  ";
        cin>>nrMetody;
    }while(nrMetody!=1 && nrMetody!=2);

    do{
        cout<<"Czy chcesz wykorzystac wbudowana macierz 4x4? (T/N):  ";
        cin>>uzycStockowej;
        if(uzycStockowej=='t' || uzycStockowej=='T') {
            wiersze = 4;
            kolumny = 5;
        }
        else if(uzycStockowej=='n' || uzycStockowej=='N') {
            cout<<endl<<"Podaj ilosc wierszy:  ";
            cin>>wiersze;
            cout<<"Podaj ilosc kolumn:  ";
            cin>>kolumny;
        } else {
            cout<<"Podano zly znak!"<<endl;
        }
    }while(uzycStockowej!='t' && uzycStockowej!='T' && uzycStockowej!='n' && uzycStockowej!='N');

    if(wiersze<=0 && kolumny<=0)
    {
        cout<<endl<<"Podano zle wymiary macierzy - koniec programu!"<<endl;
        exit(1);
    }

    double macierz[wiersze][kolumny], wyniki[wiersze];

    if(uzycStockowej=='t' || uzycStockowej=='T')
    {
        double temp_macierz[4][5] = {{1, 2, -1, 2, 0}, {1, 0, -2, 4, 4}, {0, -3, 1.5, 7, 0}, {0, -1, 1, 6, -1}};
        for(i=0; i<wiersze; i++)
            for(j=0; j<kolumny; j++)
                macierz[i][j] = temp_macierz[i][j];
    } else {
        cout<<"Wprowadzanie danych do macierzy"<<endl;
        for(i=0; i<wiersze; i++)
            for(j=0; j<kolumny; j++);
            {
                cout<<"A["<<i<<"]["<<j<<"]:  ";
                cin>>macierz[i][j];
            }
    }

    cout<<endl<<"Podana macierz:"<<endl;
    for(i=0; i<wiersze; i++)
    {
        cout<<"[";
        for(j=0; j<kolumny-1; j++)
            cout<<setw(7)<<macierz[i][j];
        cout<<"|"<<setw(7)<<macierz[i][j]<<"]"<<endl;
    }

    if(nrMetody==1) {
        n = 1;
        for(j=0; j<kolumny-2; j++)
        {
            for(i=n; i<wiersze; i++)
            {
                wspolczynnik = macierz[i][j]/macierz[n-1][j];
                for(m=0; m<kolumny; m++)
                    macierz[i][m] -= macierz[n-1][m]*wspolczynnik;
            }
            n++;
        }
        cout<<endl<<"Macierz po przeksztalceniach pierwszej serii:"<<endl;
        for(i=0; i<wiersze; i++)
        {
            cout<<"[";
            for(j=0; j<kolumny-1; j++)
                cout<<setw(7)<<macierz[i][j];
            cout<<"|"<<setw(7)<<macierz[i][j]<<"]"<<endl;
        }
        n = wiersze-2;
        for(j=kolumny-2; j>=0; j--)
        {
            for(i=n; i>=0; i--)
            {
                wspolczynnik = macierz[i][j]/macierz[n+1][j];
                for(m=0; m<kolumny; m++)
                    macierz[i][m] -= macierz[n+1][m]*wspolczynnik;
            }
            n--;
        }
        cout<<endl<<"Macierz po przeksztalceniach drugiej serii:"<<endl;
        for(i=0; i<wiersze; i++)
        {
            cout<<"[";
            for(j=0; j<kolumny-1; j++)
                cout<<setw(7)<<macierz[i][j];
            cout<<"|"<<setw(7)<<macierz[i][j]<<"]"<<endl;
        }
        for(i=0; i<wiersze; i++)
            macierz[i][kolumny-1] = wyniki[i];
        cout<<endl<<"Macierz wynikowa:"<<endl;
        for(i=0; i<wiersze; i++)
            cout<<"["<<setw(5)<<wyniki[i]<<"]"<<endl;
    } else {
        cout<<endl<<"Metoda jeszcze nie gotowa"<<endl;
    }

    /*
    cout<<endl<<"Macierz wynikowa:"<<endl;
    for(i=0; i<wiersze; i++)
        cout<<"["<<setw(5)<<wyniki[i]<<"]"<<endl;
    */
    cout<<endl;
    exit(0);
    return 0;
}
