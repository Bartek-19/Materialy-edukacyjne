#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funkcja fgets w linijce 84 pobiera wiecej niz 51 znakow */
/* Petla while w linijce 83 wykonuje o jeden obrot za duzo */

struct tKontuzja{
    char rodzaj[50];
    char rehab[50];
};

int zapis(char nazwa[], FILE *plik);

int odczyt(char nazwa[], FILE *plik);

int main()
{
    FILE *plik;
    char nazwa[] = "Zdrowie.txt";
    int wynik;

    wynik = zapis(nazwa, plik);
    if (wynik==0)
        printf("\n Zakonczono operacje zapisu.\n");

    wynik = odczyt(nazwa, plik);
    if (wynik==0)
        printf("\n Zakonczono operacje odczytu.\n\n");

    system("PAUSE");
    return 0;
}

int zapis(char nazwa[], FILE *plik)
{
    int i, n;

    plik = fopen(nazwa, "a");

    if((plik=fopen(nazwa, "a"))==NULL)
    {
        printf("Blad otwarcia\n");
        system("PAUSE");
        abort();
    }
    printf("Podaj ilosc kontuzji: ");
    scanf("%d", &n);

    struct tKontuzja tab[n];

    for(i=0; i<n; i++)
    {
        printf("Podaj rodzaj kontuzji:  ");
        fflush(stdin);
        gets(tab[i].rodzaj);
        printf("Podaj zalecane cwiczenie rehabilitacyjne:  ");
        gets(tab[i].rehab);
        fprintf(plik, "%50s", tab[i].rodzaj);
        fprintf(plik, "%50s\n", tab[i].rehab);
    }

    fclose(plik);

    return 0;
}


int odczyt(char nazwa[], FILE *plik)
{
    struct tKontuzja B;

    plik = fopen(nazwa, "r");

    if((plik=fopen(nazwa, "r"))==NULL)
    {
        printf("Blad otwarcia\n");
        system("PAUSE");
        abort();
    }

    fgetc(plik);
    fgetc(plik);
    while(!feof(plik)) {
        fgets(B.rodzaj, 51, plik);
        fgets(B.rehab, 53, plik);
        printf("Rodzaj urazu: ");
        puts(B.rodzaj);
        printf("Zalecane cwiczenie: ");
        puts(B.rehab);
    }

    return 0;
}
