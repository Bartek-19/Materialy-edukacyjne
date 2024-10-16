#include <stdio.h>
#include <stdlib.h>

//Zrobic zadanie 13.4 i 13.6

struct Tpracownik {
    char imie[20];
    char nazwisko[30];
    int liczbaGodzin;
    float stawka;
    float premia; };

struct Tpracownik wczytaj();

float obliczPlace(struct Tpracownik p);

void wyswietl(struct Tpracownik *pWsk);

int main()
{
    //Zadanie 13.3
    printf(" === ZADANIE 13.3 ===\n");

    struct Tpracownik p1, p2;
    p1 = wczytaj();
    float p1Placa = obliczPlace(p1);
    p2 = wczytaj();
    float p2Placa = obliczPlace(p2);

    printf("\n");
    wyswietl(&p1);
    printf("Placa = %.2f\n", p1Placa);
    wyswietl(&p2);
    printf("Placa = %.2f\n", p2Placa);

    //Zadanie 13.4
    printf("\n === ZADANIE 13.4 ===\n\n");
    int n, i;
    float SumaPlac = 0;
    float najwyzszaPlaca;

    printf("Podaj ilosc pracownikow: ");
    scanf("%d", &n);
    printf("\n");

    struct Tpracownik tab[n];
    float tablicaPlac[n];

    for (i=0; i<n; i++)
    {
        tab[i] = wczytaj();
        SumaPlac += obliczPlace(tab[i]);
        tablicaPlac[i] = obliczPlace(tab[i]);
    }

    najwyzszaPlaca = tablicaPlac[0];

    for (i=0; i<n; i++)
    {
        if (tablicaPlac[i] > najwyzszaPlaca)
            najwyzszaPlaca = tablicaPlac[i];
    }

    printf("\n---Lista pracownikow o najwyzszych placach: \n");

    for (i=0; i<n; i++)
    {
        if (tablicaPlac[i]==najwyzszaPlaca)
        {
            printf("Imie: %s, Nazwisko: %s\n", tab[i].imie, tab[i].nazwisko);
        }
    }

    printf("\n");
    system("PAUSE");
    return 0;
}

struct Tpracownik wczytaj()
{
    struct Tpracownik pracownik;
    fflush(stdin);
    printf("Podaj imie: ");
    gets(pracownik.imie);
    printf("Podaj nazwisko: ");
    scanf("%s", pracownik.nazwisko);
    printf("Podaj liczbe godzin: ");
    scanf("%d", &pracownik.liczbaGodzin);
    printf("Podaj stawke pracownika: ");
    scanf("%f", &pracownik.stawka);
    printf("Podaj premie pracownika: ");
    scanf("%f", &pracownik.premia);
    printf("\n");
    return pracownik;
}

float obliczPlace(struct Tpracownik p)
{
    float placa;
    placa = (p.liczbaGodzin * p.stawka) * (1 + p.premia);
    return placa;
}

void wyswietl(struct Tpracownik *pWsk)
{
    printf("  %s, %s\n", pWsk->nazwisko, pWsk->imie);
}
