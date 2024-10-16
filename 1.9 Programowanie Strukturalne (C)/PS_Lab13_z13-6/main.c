#include <stdio.h>
#include <stdlib.h>

struct tStudent {
    char imie[20];
    char nazwisko[30];
    float tablicaOcen[5];
};

void wczytywanieOcen(float tab[5]);

struct tStudent wczytaj();

float srednia(struct tStudent x);

void wyswietl(struct tStudent *xWsk);

int main()
{
    int n, i;
    float sumaOcen = 0;
    float sredniaGrupy;

    printf("--- ZADANIE 13.6 ---\n\n");

    printf("Podaj ilosc studentow: ");
    scanf("%d", &n);
    printf("\n");

    struct tStudent tab[n];
    float tablicaSrednich[n];

    for (i=0; i<n; i++)
    {
        tab[i] = wczytaj();
    }

    for (i=0; i<n; i++)
    {
        tablicaSrednich[i] = srednia(tab[i]);
        sumaOcen += srednia(tab[i]);
    }

    sredniaGrupy = sumaOcen / n;

    for (i=0; i<n; i++)
    {
        wyswietl(tab+i);
        printf("Srednia studenta: %.2f\n\n", tablicaSrednich[i]);
    }

    printf("--- Srednia grupy: %.2f\n\n", sredniaGrupy);

    system("PAUSE");
    return 0;
}

void wczytywanieOcen(float tab[5])
{
    int i;

    for (i=0; i<5; i++)
    {
        printf("Podaj ocene: ");
        scanf("%f", &tab[i]);
    }
    printf("\n");
}

struct tStudent wczytaj()
{
    struct tStudent s;
    fflush(stdin);
    printf("Podaj imie: ");
    scanf("%s", s.imie);
    printf("podaj nazwisko: ");
    scanf("%s", s.nazwisko);
    wczytywanieOcen(s.tablicaOcen);

    return s;
}

float srednia(struct tStudent x)
{
    int i;
    float S = 0;

    for (i=0; i<5; i++)
    {
        S += x.tablicaOcen[i];
    }

    S = S/5;

    return S;
}

void wyswietl(struct tStudent *xWsk)
{
    int i = 0;

    printf("Imie: %s, Nazwisko: %s,\n", xWsk->imie, xWsk->nazwisko, "Lista ocen:\t");

    while (i < 5)
    {
        printf("%.1f\t", xWsk->tablicaOcen[i]);
        i++;
    }

    printf("\n\n");
}
