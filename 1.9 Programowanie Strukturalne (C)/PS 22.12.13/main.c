#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N (5)

void wczytaj(int n, int tab[]);
void wyswietl(int n, int tab[]);
int suma(int n, int tab[]);
int maksimum(int n, int tab[]);
int zliczanie(int n, int tab[]);
//-------
int minimum_W(int n, int tab[]);
float srednia_W(int n, int tab[]);
void losuj_W(int n, int tab[]);
int zliczanie_W(int n, int tab[]);
//-------
void wczytaj2(int n, int m, int tab[n][m]);
void wyswietl2(int n, int m, int tab[n][m]);
int suma2(int n, int m, int tab[n][m]);
int maksimum2(int n, int m, int tab[n][m]);
float srednia2(int n, int m, int Suma);
//-------
void kopia1(int tab1[], int tab2[], int n);
void kopia2(int tab1[], int tab2[], int n);
//-------
void wczytywanieOcen(int n, float tab[]);
void wyswietlanieOcen(int n, float tab[]);
bool wyniki(int n, float tab[]);
void lista(int n, float tab[]);





int main()
{
    int wybor;

    int n;
    int ile;
    int max;

    printf("Podaj liczbe elementow tablicy drugiej z zadania 10.2: ");
    scanf("%d", &n);

    int tab1[N];
    int tab2[n];

    int tab3[] = {1, 3, 7, 9};
    int tab4[3];
    int tab5[n];

    int kol, wier;
    int S;
    int tab6[5][4];

    int tablicaWstepna[n];
    int kopiaTablicowa[n];
    int kopiaWskaznikowa[n];

    float oceny[n];
    bool zdali = true;


    while (wybor)
    {
        printf("\n MENU PROGRAMU:\n");
        printf("0. Wyjscie z programu.\n");
        printf("1. Zadanie 10.2 - tablice jednowymiarowe - zapis tablicowy.\n");
        printf("2. Zadanie 10.3 - tablice jednowymiarowe - zapis wskaznikowy.\n");
        printf("3. Zadanie 10.3 - tablice dwuwymiarowe.\n");
        printf("4. Zadanie 10.5 - tablice jednowymiarowe - kopiowanie tablic.\n");
        printf("5. Zadanie 10.6 - oceny studentow.\n");

        printf("Podaj numer z menu: ");
        scanf("%d", &wybor);


        if (wybor == 0)
        {
            printf("\n\t 'KONIEC PROGRAMU' \n\n");
        }

    //--------------------
        if (wybor == 1)
        {
            printf("\n\t 'TABLICE JEDNOWYMIAROWE' (Zadanie 10.2)\n\n");

            printf("--- tab1 ---\n");
            wczytaj(N, tab1);
            wyswietl(N, tab1);
            printf("\n");
            max = maksimum(N, tab1);
            printf("Najwiekszy element tablicy: %d\n", max);
            printf("Suma elementow = %d\n", suma(N, tab1));
            ile = zliczanie(N, tab1);
            printf("Szukany element wystepuje %d razy.\n", ile);
            printf("\n");

            printf("--- tab2 ---\n");
            wczytaj(n, tab2);
            wyswietl(n, tab2);
            printf("\n");
            max = maksimum(n, tab2);
            printf("Najwiekszy element tablicy: %d\n", max);
            printf("Suma elementow = %d\n", suma(n, tab2));
            ile = zliczanie(n, tab2);
            printf("Szukany element wystepuje %d razy.\n", ile);
            printf("\n");
            fflush(stdin);
        }

    //--------------------
        if (wybor == 2)
        {
            printf("\n\t 'TABLICE JEDNOWYMIAROWE' (Zadanie 10.3.1)\n\n");

            printf("--- tab3 ---\n");
            int r = sizeof(tab3)/sizeof(int);
            wyswietl(r, tab3);
            printf("\n");
            printf("Najmniejszy element tablicy: %d\n", minimum_W(r, tab3));
            printf("Srednia elementow tablicy: %f\n", srednia_W(r, tab3));
            printf("\n");
            ile = zliczanie_W(r, tab3);
            printf("Szukany element wystepuje w tablicy %d razy.\n", ile);
            printf("\n");


            printf("--- tab4 ---\n");
            wczytaj(3, tab4);
            wyswietl(3, tab4);
            printf("\n");
            printf("Najmniejszy element tablicy: %d\n", minimum_W(3, tab4));
            printf("Srednia elementow tablicy: %f\n", srednia_W(3, tab4));
            printf("\n");
            ile = zliczanie_W(3, tab4);
            printf("Szukany element wystepuje w tablicy %d razy.\n", ile);
            printf("\n");


            printf("--- tab5 ---\n");
            printf("Podaj ilosc elementow tablicy: ");
            scanf("%d", &n);
            losuj_W(n, tab5);
            printf("\n");
            printf("Najmniejszy element tablicy: %d\n", minimum_W(n, tab5));
            printf("Srednia elementow tablicy: %f\n", srednia_W(n, tab5));
            printf("\n");
            ile = zliczanie_W(n, tab5);
            printf("Szukany element wystepuje w tablicy %d razy.\n", ile);
            printf("\n");
            fflush(stdin);
        }

    //--------------------
        if (wybor == 3)
        {
            printf("\n\t 'TABLICE DWUWYMIAROWE' (Zadanie 10.3.2)\n\n");

            printf("--- tablica dwuwymiarowa 1---\n");
            wczytaj2(5, 4, tab6);
            wyswietl2(5, 4, tab6);
            printf("\n");
            printf("Najwiekszy element tablicy: %d\n", maksimum2(5, 4, tab6));
            S = suma2(5, 4, tab6);
            printf("Suma elementow = %d\n", S);
            printf("Srednia elementow wynosi:  %f\n", srednia2(5, 4, S));
            printf("\n");


            printf("--- tablica dwuwymiarowa 2---\n");
            printf("Podaj ilosc kolumn: ");
            scanf("%d", &kol);
            printf("Podaj ilosc wierszy: ");
            scanf("%d", &wier);
            int tab7[kol][wier];
            wczytaj2(kol, wier, tab7);
            wyswietl2(kol, wier, tab7);
            printf("Najwiekszy element tablicy: %d\n", maksimum2(kol, wier, tab7));
            S = suma2(kol, wier, tab7);
            printf("Suma elementow = %d\n", S);
            printf("Srednia elementow wynosi:  %f\n", srednia2(kol, wier, S));
            printf("\n");
            fflush(stdin);
        }

    //--------------------
        if (wybor == 4)
        {
            printf("\n\t 'KOPIOWANIE TABLIC' (Zadanie 10.5)\n\n");
            printf("Podaj ilosc elementow tablicy: ");
            scanf("%d", &n);
            wczytaj(n, tablicaWstepna);
            printf("Zawartosc tablicy wstepnej:\n");
            wyswietl(n, tablicaWstepna);
            printf("\n");
            kopia1(tablicaWstepna, kopiaTablicowa, n);
            printf("\n");
            kopia2(tablicaWstepna, kopiaWskaznikowa, n);
            printf("\n");
            fflush(stdin);
        }

    //--------------------
        if (wybor == 5)
        {
            printf("\n\t 'SPRAWDZANIE OCEN STUDENTOW' (Zadanie 10.6)\n\n");
            printf("Podaj ilosc studentow, ktorzy przystapili do egzaminu: ");
            scanf("%d", &n);
            wczytywanieOcen(n, oceny);
            printf("\n");
            wyswietlanieOcen(n, oceny);
            printf("\n");
            zdali = wyniki(n, oceny);
            if (zdali == false)
            {
                lista(n, oceny);
            }
            else
                printf("Wszyscy studenci zdali egzamin.\n");
            printf("\n");
            fflush(stdin);
        }

    //--------------------
        if (wybor < 0 || wybor > 5)
        {
            printf("\n ! Podano zly numer ! \n");
            fflush(stdin);
        }

    //--------------------
    }


    system("PAUSE");
    return 0;
}



//                                          =====
//                                      do zadania 10.2
//                                          =====
void wczytaj(int n, int tab[])
{
    int i;

    for (i =0; i<n; i++)
    {
        printf("Podaj element tab[%d]:  ", i);
        scanf("%d", &tab[i]);
    }
}

void wyswietl(int n, int tab[])
{
    int i;
    for (i = 0; i<n; i++)
    {
        //printf("%d\t", tab[i]);
        printf("%d\t", *(tab+i));
    }
}

int suma(int n, int tab[])
{
    int i;
    int S = 0;

    for (i=0; i<n; i++)
    {
        S += tab[i];
    }

    return S;
}

int maksimum(int n, int tab[])
{
    int max = tab[0];
    int i;

    for (i=0; i<n; i++)
    {
        if (tab[i] > max)
            {max = tab[i];}
    }

    return max;
}

int zliczanie(int n, int tab[])
{
    int ile = 0;
    int X;
    int i;

    printf("Podaj szukany element:  ");
    scanf("%d", &X);

    for (i=0; i<n; i++)
    {
        if (tab[i] == X) ile++;
    }

    return ile;
}



//                                          =====
//                                      do zadania 10.3.1
//                                          =====
int minimum_W(int n, int tab[])
{
    int min = *tab;
    int i;

    for (i=0; i<n; i++)
    {
        if (*(tab+i) < min)
            {min = *(tab+i);}
    }

    return min;
}

float srednia_W(int n, int tab[])
{
    int i;
    int S = 0;

    for (i=0; i<n; i++)
    {
        S += *(tab+i);
    }

    S = (float)S/n;

    return S;
}

void losuj_W(int n, int tab[])
{
    int i;

    for (i=0; i<n; i++)
    {
        *(tab+i) = rand() % 10;
        printf("%d\t", *(tab+i));
    }
}

int zliczanie_W(int n, int tab[])
{
    int ile = 0;
    int X;
    int i;

    printf("Podaj szukany element:  ");
    scanf("%d", &X);

    for (i=0; i<n; i++)
    {
        if (*(tab+i) == X) ile++;
    }

    return ile;

}



//                                          =====
//                                      do zadania 10.3.2
//                                          =====
void wczytaj2(int n, int m, int tab[n][m])
{
    int i, j;

    for (j=0; j<m; j++)
    {
        i = 0;
        for (i=0; i<n; i++)
        {
            printf("Podaj element tab[%d][%d]:  ", i, j);
            scanf("%d", &tab[i][j]);
        }
    }
}

void wyswietl2(int n, int m, int tab[n][m])
{
    int i, j;

    for (j=0; j<m; j++)
    {
        i = 0;
        for (i=0; i<n; i++)
        {
            printf("%d\t", tab[i][j]);
            if (i == n-1) printf("\n");
        }
    }
}

int suma2(int n, int m, int tab[n][m])
{
    int i, j;
    int S = 0;

    for (j=0; j<m; j++)
    {
        i = 0;
        for (i=0; i<n; i++)
        {
            S += tab[i][j];
        }
    }

    return S;
}

int maksimum2(int n, int m, int tab[n][m])
{
    int i, j;
    int max = tab[0][0];

    for (j=0; j<m; j++)
    {
        i = 0;
        for (i=0; i<n; i++)
        {
            if (tab[i][j] > max)
                {max = tab[i][j];}
        }
    }

    return max;
}

float srednia2(int n, int m, int Suma)
{
    float srednia;

    srednia = (float)Suma/(n*m);

    return srednia;
}



//                                          =====
//                                      do zadania 10.5
//                                          =====
void kopia1(int tab1[], int tab2[], int n)
{
    int i;

    printf("Kopia tablicy z zapisem tablicowym:\n");

    for (i=0; i<n; i++)
    {
        tab2[i] = tab1[i];
        printf("%d\t", tab2[i]);
    }
}

void kopia2(int tab1[], int tab2[], int n)
{
    int i;

    printf("Kopia tablicy z zapisem wskaznikowym:\n");

    for (i=0; i<n; i++)
    {
        *(tab2+i) = *(tab1+i);
        printf("%d\t", *(tab2+i));
    }
    //Wyswietla sie zly wynik
}



//                                          =====
//                                      do zadania 10.6
//                                          =====
void wczytywanieOcen(int n, float tab[])
{
    int i;

    for (i=0; i<n; i++)
    {
        printf("Podaj ocene z egzaminu %d. studenta: ", i+1);
        scanf("%f", &tab[i]);
    }
}

void wyswietlanieOcen(int n, float tab[])
{
    int i;

    for (i=0; i<n; i++)
    {
        printf("Ocena z egzaminu studenta %d:\t %.1f \n", i+1, tab[i]);
    }
}

bool wyniki(int n, float tab[])
{
    int i;
    int nieZdali = 0;

    for (i=0; i<n; i++)
    {
        if (tab[i] < 3)
        {
            nieZdali++;
        }
    }

    if (nieZdali == 0)
        return true;
    else
        return false;
}

void lista(int n, float tab[])
{
    int i, j;
    int k = 0;

    for (i=0; i<n; i++)
    {
        if (tab[i] < 3)
            k++;
    }

    printf("\nLacznie egzaminu nie zdalo %d studentow.\n", k);

    int nieZdali[k];

    printf("Egzaminu nie zdali studenci o numerach:\n");
    for (j=0; j<k; j++)
    {
        printf("%d\n", nieZdali[j]);
    }

    printf("\n");
    //Lista pokazuje niewlasciwe numery studentow
}
