#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define PRZEDMIOT "Programowanie Strukturalne"

void wysrodkowanie(char tab[]);
void doLewej(char tab[][80], int x);
void doPrawej(char tab[]);

int main()
{
    setlocale(LC_ALL,"");

    int n = 80;

    //Zad 12.3
    char imie1[] = "Bartosz ";
    char nazwisko1[] = "Klimiuk";
    char imie2[20], nazwisko2[30];
    char str1[n];

    wysrodkowanie("ZADANIE 12.3");
    printf("\n");

    wysrodkowanie(PRZEDMIOT);

    strcpy(str1, imie1);
    strcat(str1, nazwisko1);
    wysrodkowanie(str1);

    printf("Podaj imie:  ");
    scanf("%s", imie2);
    printf("Podaj nazwisko:  ");
    scanf("%s", nazwisko2);
    strcat(imie2, " ");
    strcat(imie2, nazwisko2);
    wysrodkowanie(imie2);
    printf("\n\n");


    //Zad 12.4

    wysrodkowanie("ZADANIE 12.4");
    printf("\n");

    int i;
    char wiersz[][80] = {"Stoi na stacji lokomotywa,", "Ciezka, ogromna i pot z niej splywa:", "Tlusta oliwa.", "Stoi i sapie, dyszy i dmucha,",
                          "Zar z rozgrzanego jej brzucha bucha:", "Buch - jak goraco!", "Uch - jak goraco!"};

    for (i=0; i<7; i++)
        wysrodkowanie(wiersz[i]);

    printf("\n");

    doLewej(wiersz, 7);

    printf("\n");

    for (i=0; i<7; i++)
    {
        doPrawej(wiersz[i]);
    }

    printf("\n");
    system("PAUSE");
    return 0;
}

void wysrodkowanie(char tab[])
{
    int x, i;
    x = (80 - strlen(tab))/2;

    char napis[80];

    for(i = 0; i<x; i++)
        napis[i] = ' ';

    napis[i] = '\0';

    strcat(napis, tab);
    puts(napis);
}

void doLewej(char tab[][80], int x)
{
    int i;

    for (i=0; i<x; i++)
        puts(tab[i]);
}

void doPrawej(char tab[])
{
    int i, x;
    char napis[80];

    x = 80 - strlen(tab);

    for (i=0; i<x; i++)
        napis[i] = ' ';

    napis[i] = '\0';

    strcat(napis, tab);
    puts(napis);
}

