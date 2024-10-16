#include <stdio.h>
#include <stdlib.h>

float zamiana(float *a, float *b);
int Zad9_4(int *n, int *il);
void Zad9_5(float *c);
int Zad9_6(int *L1, int *L2, int n);


int main()
{
    int wybor;    /*Wybor zadania*/
    float x, y;    /*Zadanie 9.2*/
    int ilosc, il;    /*Zadanie 9.4*/
    int k = 3; int liczba = 1; float L;    /*Zadanie 9.5*/
    int D, Z, n;    /*Zadanie 9.6*/

    while (wybor != 0){

        printf("MENU PROGRAMU:\n \
               0. Wyjscie z programu,\n \
               1. Zadanie 9.2,\n \
               2. Zadanie 9.4,\n \
               3. Zadanie 9.5,\n \
               4. Zadanie 9.6,\n");

        printf("Podaj numer zadania:  ");
        scanf("%d", &wybor);

        switch(wybor){

        case 0:
            break;

        case 1:
            printf("ZADANIE 9.2\n");
            printf("Podaj X, Y:  ");
            scanf("%f %f", &x, &y);
            printf("X = %f, adres X = %p    \n", x, &x);
            printf("Y = %f, adres Y = %p    \n", y, &y);
            printf("\n");
            zamiana(&x, &y);
            printf("X = %f, adres X = %p    \n", x, &x);
            printf("Y = %f, adres Y = %p    \n", y, &y);
            printf("\n");
            break;

        case 2:
            printf("ZADANIE 9.4\n");
            printf("Podaj ilosc liczb:  ");
            scanf("%d", &ilosc);

            Zad9_4(&ilosc, &il);
            printf("\n\n");
            break;

        case 3:
            printf("ZADANIE 9.5\n");

            while (liczba<=k)
            {
                printf("Podaj liczbe numer %d:  ", liczba);
                scanf("%f", &L);
                Zad9_5(&L);
                liczba++;
            }

            printf("\n\n");
            break;

        case 4:
            printf("ZADANIE 9.6\n");
            printf("Podaj ilosc liczb:  ");
            scanf("%d", &n);
            Zad9_6(&D, &Z, n);
            printf("Sposrod podanych liczb %d bylo dodatnich, a %d rownych zero.", D, Z);
            printf("\n\n");
            break;

        default:
            printf("Podaj inna liczbe.\n");
            break;
        }
    }


    getchar();
    getchar();

    return 0;
}


float zamiana(float *a, float *b)
{
    float temp = *a;

    *a = *b;
    *b = temp;
}


int Zad9_4(int *n, int *il)
{
    /*Program nie wyswietla prawidlowego iloczynu*/

    int i, x, licz, iloczyn;
    i = 1;
    licz = 0;
    iloczyn = 1;

    while (i<=*n){
        printf("Podaj liczbe:  ");
        scanf("%d", &x);
        if (x>100 || x<1)
            {i++;
            continue;}
        iloczyn *= x;
        licz++;
        i++;
    }

    *il = iloczyn;

    if (licz>0)
        printf("Podano %d liczb w zakresie od 1 do 100,\n \
               ich iloczyn wynosi %d.\n", licz, il);
    else
        printf("Nie podano zadnej liczby w zakresie od 1 do 100.\n");
}


void Zad9_5(float *c)
{
    /*Zadanie wyswietla zly wynik*/

    printf("-\n Czesc calkowita liczby = %.0d , czesc ulamkowa = %0.f \n\n", c, c);
}


int Zad9_6(int *L1, int *L2, int n)
{
    int i = 1;
    float x;
    int dod = 0, zero = 0;

    while (i<=n)
    {
        printf("Podaj liczbe:  ");
        scanf("%f", &x);
        if (x>0) dod++;
        if (x==0) zero++;
        i++;
    }

    *L1 = dod;
    *L2 = zero;
}
