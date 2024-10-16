#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Zad7_2(int n, char c);
void Prostokat(int m, int n, char c);
float Zad7_3(int n);
void Kody(char a, char b);
void Zad7_4(int n);
void Zad7_5();
float Zad7_6(float x, int K);



int main()
{
    int m, n;
    char znak, znak1, znak2;
    int wybor;
    float alfa;
    int dokladnosc;

    printf("0. KONIEC PROGRAMU.\n");
    printf("1. Slaczek (Zadanie 7.2).\n");
    printf("2. Prostokat.\n");
    printf("3. Srednia liczb parzystych (Zadanie 7.3).\n");
    printf("4. Zbior znakow (na bazie kodow ASCII).\n");
    printf("5. Pensje pracownikow (Zadanie 7.4).\n");
    printf("6. Sprawdzenie ciagu arytmetycznego (Zadanie 7.5).\n");
    printf("7. Obliczanie sinusa (Zadanie 7.6)\n");
    printf("\n");

while (wybor != 0){
    printf("Podaj numer z menu: ");
    scanf("%d", &wybor);

    switch (wybor){
        case 0:
            break;
        case 1:
            printf("Zadanie 7.2\n");
            printf("Podaj znaczek: ");
            getchar();
            scanf("%c", &znak);
            printf("Podaj ilosc znakow: ");
            scanf("%d", &m);
            Zad7_2(m, znak);
            printf("\n");
            break;

        case 2:
            printf("Prostokat\n");
            printf("Podaj znak: ");
            getchar();
            scanf("%c", &znak);
            printf("Podaj dlugosc prostokata: ");
            scanf("%d", &n);
            printf("Podaj szerokosc prostokata: ");
            scanf("%d", &m);
            Prostokat(m, n, znak);
            printf("\n");
            break;

        case 3:
            printf("Zadanie 7.3\n");
            printf("Podaj ilosc liczb: ");
            scanf("%d", &n);
            printf("Srednia liczb parzystych; %f", Zad7_3(n));
            printf("\n");
            break;

        case 4:
            printf("Kody ASCII\n");
            printf("Podaj pierwszy znak: ");
            getchar();
            scanf("%c", &znak1);
            printf("Podaj ostatni znak: ");
            getchar();
            scanf("%c", &znak2);
            Kody(znak1, znak2);
            printf("\n");
            break;

        case 5:
            printf("zadanie 7.4\n");
            printf("Podaj ilosc pracownikow: ");
            scanf("%d", &n);
            Zad7_4(n);
            printf("\n");
            break;

        case 6:
            printf("Zadanie 7.5\n");
            Zad7_5();
            printf("\n");
            break;

        case 7:
            printf("Zadanie 7.6\n");
            printf("Podaj miare kata: ");
            scanf("%f", &alfa);
            printf("Podaj ilosc elementow ");
            printf("(im wiecej elementow tym wieksza dokladnosc): ");
            scanf("%d", &dokladnosc);
            printf("Sinus kata wynosi:  %1.10f\n", Zad7_6(alfa, dokladnosc));
            printf("\n");
            break;

        default:
            printf("Podano zly numer!\n");
            printf("\n");
            break;
    }
}

printf("\n");
printf("***** Koniec programu *****\n");

    system("PAUSE");
    return 0;
}

void Zad7_2(int n, char c)
{
    int i;

    for (i=1; i<=n; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}

void Prostokat(int m, int n, char c)
{
    int i, j;

    for (j=1; j<=m; j++)
    {
        for (i=1; i<=n; i++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
}

float Zad7_3(int n)
{
    int liczba, i;
    float s;

    s = 0;

    for (i=1; i<=n; i++)
    {
        printf("Podaj liczbe: ");
        scanf("%d", &liczba);
        if (liczba%2 == 0)
            s += liczba;
    }
    s = s/n;
    return s;
}

void Kody(char a, char b)
{
    char x;

    for (x=a; x<=b; x++)
    {
        printf(" %c ", x);
    }
    printf("\n");
}

void Zad7_4(int n)
{
    int i;
    float stara, nowa;

    for (i=1; i<=n; i++)
    {
        printf("Lp. %d \t", i);
        printf("Podaj pensje pracownika: ");
        scanf("%f", &stara);
        if (stara > 5000)
        { nowa = stara * 1.05;
          printf("\t\t Nowa pensja: %.2f \n", nowa);
        }
        else if (stara <= 5000)
            { nowa = stara * 1.1;
              printf("\t\t Nowa pensja: %.2f \n", nowa);
            }
            else if (stara < 0) printf("\t\t Podano zla pensje! \n");
    }
}

void Zad7_5()
{
    int n;

    printf("Podaj ilosc elementow: ");
    scanf("%d", &n);

    int i, j;
    float CiagArytmetyczny[n-1];
    float x, pierwszy, drugi, trzeci;
    char CzyCiag;

    for (i=0; i<n; i++)
    {
        printf("Podaj %d wyraz ciagu: ", i+1);
        scanf("%f", &x);
        CiagArytmetyczny[i] = x;
    }

    for (j=0; j<(n-2); j++)
    {
        pierwszy = CiagArytmetyczny[j];
        drugi = CiagArytmetyczny[j+1];
        trzeci = CiagArytmetyczny[j+2];
        if (trzeci - drugi == drugi - pierwszy)
        {CzyCiag = 'T';
         continue;
        }
        else{CzyCiag = 'F';
             break;
            };
    }

    printf("Czy ciag jest arytmetyczny? %c\n", CzyCiag);
}

float Zad7_6(float x, int K)
{
    int i;
    float licznik, mianownik, sinus, wyraz;

    sinus = 0;
    mianownik = 0;

    for (i=0; i<=K; i++)
    {
        licznik = x * pow(-1, i);
        while (i<=(2*i+1))  mianownik = mianownik*i;
        wyraz = licznik/mianownik;
        sinus += wyraz;
    }

    return sinus;
}
