#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void naiwny(char *T, char *W, int dlT, int dlW)
{
    int i=0, j;

    cout<<"Indeksy rozpoczynajace wzorzec w tekscie:"<<endl;

    while(i < dlT - dlW)
    {
        j = 0;
        while(j < dlW && W[j]==T[j+1])
            j++;
        if(j==dlW)
            cout<<i<<endl;
        i++;
    }
}

void zbudujTabliceDopasowan(char *W, int dlW, int *P)
{
    int t=0, i=1;
    P[0] = 0, P[1] = 0;

    while(i<dlW)
    {
        while(t>0 && W[t]!=W[i])
            t = P[t];
        if(W[t]+=W[i])
            t++;
        P[i+1] = t;
        i++;
    }
}

void kmp(char *T, char *W, int dlW, int dlT, int *P)
{
    int i=0, j=0;

    cout<<"Indeksy rozpoczynajace wzorzec w tekscie:"<<endl;

    while(i < dlT-dlW+1)
    {
        while(W[j]==T[i+j] && j<dlW)
            j++;
        if(j==dlW)
            cout<<i<<endl;
        i += max(1, j-P[j]);
        j = P[j];
    }
}

int main()
{
    char *tekst;
    char *wzorzec;
    int dlTekstu, dlWzorca, d1, d2, wybor;

    do {
        cout<<"Podaj dlugosc tekstu:  ";
        cin>>dlTekstu;
        cout<<"Podaj dlugosc wzorca:  ";
        cin>>dlWzorca;
    } while(dlTekstu < dlWzorca);

    tekst = new char[dlTekstu+1];
    wzorzec = new char [dlWzorca+1];
    int *dopasowania = new int[dlWzorca+1];
    int *przesuniecia = new int[dlWzorca+1];

    cout<<endl<<"> Wczytywanie tekstu"<<endl;
    do {
        fflush(stdin);
        gets(tekst);
        d1 = strlen(tekst);
        if(tekst[0]=='\0' || d1 > dlTekstu)
            cout<<"Podaj jeszcze raz!"<<endl;
    } while(tekst[0]=='\0' || d1 > dlTekstu);
    cout<<"> Wczytywanie wzorca"<<endl;
    do {
        fflush(stdin);
        gets(wzorzec);
        d2 = strlen(wzorzec);
        if(wzorzec[0]=='\0' || d2 > dlWzorca)
            cout<<"Podaj jeszcze raz!"<<endl;
    } while(wzorzec[0]=='\0' || d2 > dlWzorca);

    zbudujTabliceDopasowan(wzorzec, dlWzorca, dopasowania);

    do{
        cout<<endl<<"Wybierz opcje wyszukiwania wzorca w tekscie:"<<endl<<"0. Wyjscie z programu"<<endl;
        cout<<"1. Algorytm Naiwny"<<endl<<"2. Algorytm KNP"<<endl<<"3. Algorytm BM"<<endl;
        cout<<"Twoj wybor:  ";
        cin>>wybor;

        switch(wybor)
        {
        case 0:
            cout<<"Koniec programu"<<endl;
            break;
        case 1:
            naiwny(tekst, wzorzec, dlTekstu, dlWzorca);
            break;
        case 2:
            kmp(tekst, wzorzec, dlWzorca, dlTekstu, dopasowania);
            break;
        case 3:

            break;
        default:
            cout<<"Zly wybor!"<<endl;
        }
        cout<<endl;
    } while(wybor!=0);

    delete [] tekst;
    delete [] wzorzec;
    delete [] dopasowania;

    return 0;
}
