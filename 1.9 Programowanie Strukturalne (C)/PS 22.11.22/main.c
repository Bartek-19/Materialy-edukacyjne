#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float SredniaWhile(int n);
float SredniaDoWhile(int n);
float SredniaFor(int n);
void SredniaLiczb();
float Najwieksza(float nowa, float a);
void ZnakiWZdaniu();


/*Zadanie 6.2 (numery w menu od 1 do 3)
nie pokazuja za kazdym razem dobrego wyniku*/


/*Zadanie 6.5 (numer w menu 6)
pokazuje zly wynik na konsoli*/


int main()
{
    int n;
    int numer = 1;
    float pobrana = 0;
    float a;

    while (numer)
    {

        printf("1. Srednia while.\n");
        printf("2. Srednia do while.\n");
        printf("3. Srednia for.\n");
        printf("4. Srednia liczb parzystych i nieparzystych.\n");
        printf("5. Znaki w zdaniu.\n");
        printf("6. Najwieksza liczba.\n");
        printf("0. Koniec programu.\n\n");

        printf("Wybierz opcje: ");
        scanf("%d", &numer);
        printf("\n\n");

        if (numer == 1)
        {
            printf("Podaj ilosc liczb: ");
            scanf("%d", &n);

            printf( "Srednia = %5.2f\n", SredniaWhile(n) );
            printf("\n");
        }

        else if (numer == 2)
        {
            printf("Podaj ilosc liczb: ");
            scanf("%d", &n);

            printf( "Srednia = %5.2f\n", SredniaDoWhile(n) );
            printf("\n");
        }

        else if (numer == 3)
        {
            printf("Podaj ilosc liczb: ");
            scanf("%d", &n);

            printf( "Srednia = %5.2f\n", SredniaFor(n) );
            printf("\n");
        }

        else if (numer == 4)
        {
            SredniaLiczb();
            printf("\n");
        }

        else if (numer == 5)
        {
            ZnakiWZdaniu();
            printf("\n");
        }

        else if (numer == 6)
        {
            printf("(Aby zakonczyc program wpisz -1)\n\n");

            while (pobrana != -1)
            {
                printf("Podaj liczbe: ");
                scanf("%f", &pobrana);
                Najwieksza(pobrana, a);
            }

            printf( "Najwieksza liczba wynosi: %f\n", a);
            printf("\n");
        }

        else;
    }

    printf("\nKoniec programu.\n\n");
    return 0;
}


/*Zadanie 6.2*/
float SredniaWhile (int n)
{
    int i;
    float a;
    float s;

    i = 1;
    while (i<=n)
    {
        printf("Podaj liczbe numer %d: ", i);
        scanf("%f", &a);
        s += a;
        i++;
    }

    return s/n;
}


/*Zadanie 6.2*/
float SredniaDoWhile (int n)
{
    int i;
    float a;
    float s;

    i = 1;
    s = 0;

    do
    {
        printf("Podaj liczbe numer %d: ", i);
        scanf("%f", &a);
        s+=a;
        i++;
    }
    while (i<=n);

    return s/n;
}


/*Zadanie 6.2*/
float SredniaFor(int n)
{
    int i;
    float a;
    float s;

    i = 1;
    s = 0;

    for (i=1; i<=n; i++)
    {
        printf("Podaj liczbe numer %d: ", i);
        scanf("%f", &a);
        s+=a;
    }

    return s/n;
}


/*Zadanie 6.3*/
void SredniaLiczb()
{
    int x;
    int S1, n1, S2, n2;

    S1 = 0;
    n1 = 0;
    S2 = 0;
    n2 = 0;

    while (x != 0)
    {
        printf("Podaj liczbe (wpisz 0 aby zakonczyc wczytywanie): ");
        scanf("%d", &x);

        if (x%2 == 0 && x != 0)
        {
            S1 += x;
            n1 += 1;
        }
        else
            if (x%2 == 1)
            {
                S2 += x;
                n2 += 1;
            }
    }

    printf("Srednia liczb parzystych wynosi: %f\n", (float)S1/n1);
    printf("Srednia liczb nieparzystych wynosi: %f\n", (float)S2/n2);
}


/*Zadanie 6.4*/
void ZnakiWZdaniu()
{
    char litera, cyfra, znak;
    int n1, n2;
    n1 = 0;
    n2 = 0;

    getchar();
    printf("Podaj szuakna litere: ");
    scanf("%c", &litera);

    getchar();
    printf("Podaj szuakna cyfre: ");
    scanf("%c", &cyfra);

    printf("zapisz zdanie zakonczone kropka.\n");
    while (znak != '.')
    {
        scanf("%c", &znak);
        if (znak == litera) {n1 += 1;}
        else
            if (znak == cyfra) {n2 += 1;}
            else;
    }

    printf("Szukana litera wystepuje w zdaniu %d razy, a cyfra %d razy.\n", n1, n2);
}


/*Zadanie 6.5*/
float Najwieksza(float nowa, float a)
{
    if (nowa <= a)
        {return a;}
    else
        if (nowa > a)
            {a = nowa;
            return a;}
}
