#include <stdio.h>
#include <stdlib.h>

struct Zad3_pracownik {
    char imie[20];
    char nazwisko[30];
    int LiczbaGodzin;
    float stawka;
    int premia;
    float wyplata;

};

struct Zad3_pracownik wczytaj();

int main()
{
    struct Zad3_pracownik Pracownik;

    Pracownik = wczytaj();

    FILE *plik;
    plik = fopen("Zad3.txt", "w");

    fputs(Pracownik.imie, plik);
    putc('\n', plik);
    fputs(Pracownik.nazwisko, plik);
    putc('\n', plik);
    fprintf(plik, "Wyplata: %.2f\n", Pracownik.wyplata);

    fclose(plik);

    system("PAUSE");
    return 0;
}

struct Zad3_pracownik wczytaj()
{
    struct Zad3_pracownik p;
    float W;
    printf("Podaj imie: ");
    scanf("%s", p.imie);
    printf("Podaj nazwisko: ");
    scanf("%s", p.nazwisko);
    printf("Podaj liczbe godzin: ");
    scanf("%d", &p.LiczbaGodzin);
    printf("Podaj stawke pracownika: ");
    scanf("%f", &p.stawka);
    printf("Podaj premie przyslugujaca pracownikowi (w procentach): ");
    scanf("%d", &p.premia);
    W = p.LiczbaGodzin * p.stawka * (1 + p.premia / 100.0);
    p.wyplata = W;

    return p;
}
