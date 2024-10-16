#include <stdio.h>
#include <stdlib.h>
#include "TabliceDyn.h"

int main()
{
    int n;
    float *tablica1;

    printf("Podaj ilosc elementow tablicy: ");
    scanf("%d", &n);

    tablica1 = utworzTD(n);

    wyswietlTD(tablica1, n);

    usunTD(tablica1);

    float **tablica2;
    int w, k;

    printf("\ntablica 2D\n");
    printf("Podaj liczbe wierszy tablicy ");
    scanf("%d",&w);
    printf("Podaj liczbe kolumn tablicy ");
    scanf("%d",&k);

    tablica2 = utworzT2D(w, k);

    wyswietlT2D(tablica2, w, k);

    int *tablica3[100], *tablica4;
    int a, b;
    int *m = 0;

    printf("\n\n Zadanie 11.5 \n\n");

    losuj(tablica3, 100);

    printf("Podaj dolna granice szukanego przedzialu: ");
    scanf("%d", &a);
    printf("Podaj gorna granice szukanego przedzialu: ");
    scanf("%d", &b);

    tablica4 = nowatabDyn(tablica3, 100, a, b, m);

    wyswietlTEST(tablica4, m);

    system("PAUSE");
    return 0;
}
