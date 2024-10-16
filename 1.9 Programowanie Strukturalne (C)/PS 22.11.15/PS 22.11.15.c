#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Zad5_4(float x, float y);

void Zad5_5(float a, float b, float c, float delta);

float Zad5_6(float a, float b, float c);

void Zad5_7(int miesiac);

void Zad5_8(int bilet, int n1, int n2, int n3, int n4, int n5, int n6);


int main(){
    int num;
    float x, y;
    float a1, b1, c1, delta;
    float aa, bb, cc;
    int miesiac;
    int bilet, n1, n2, n3, n4, n5, n6;

    printf("menu programu\n");
    printf("1. Zadanie 5_4 (Sprawdzanie polozenia punktu w obszarze)\n");
    printf("2. Zadanie 5_5 (Wyznaczanie pierwiastkow rownania kwadratowego)\n");
    printf("3. Zadanie 5_6 (Pole trojkata)\n");
    printf("4. Zadanie 5_7 (Analiza miesiaca)\n");
    printf("5. Zadanie 5_8 (Szczesliwy bilet)\n");

    printf("--------------------------------------\n");

    printf("Podaj numer z menu: \n");
    scanf("%d", &num);

    switch (num)
    {
    case 1:

        Zad5_4(x, y);  break;

    case 2:

        printf("Podaj wspolczynnik a\n");
        scanf("%f", &a1);

        printf("Podaj wspolczynnik b\n");
        scanf("%f", &b1);

        printf("Podaj wspolczynnik c\n");
        scanf("%f", &c1);

        Zad5_5(a1, b1, c1, delta);  break;

    case 3:

        printf("Podaj boki trojkata: \n");
        scanf("%f %f %f", &aa, &bb, &cc);

        printf("Pole = %f\n", (float)Zad5_6(aa, bb, cc));  break;

    case 4:

        Zad5_7(miesiac);  break;

    case 5:

        printf("Podaj szesciocyfrowy numer biletu tramwajowego: ");
        scanf("%d", &bilet);

        Zad5_8(bilet, n1, n2, n3, n4, n5, n6);  break;

    default: printf("Zly numer wyboru\n");
    }

system("PAUSE");
return 0;
}


void Zad5_4(float x, float y)
{
    printf("Podaj x: ");
    scanf("%f", &x);

    printf("Podaj y: ");
    scanf("%f", &y);

    if (x<=1 && x>=-1 && y<=1 && y>=-1)
        printf("Punkt nalezy do zaznaczonego obszaru\n");
    else printf("Punkt nie nalezy do zaznaczonego obszaru\n");
}


void Zad5_5(float a, float b, float c, float delta)
{
    if (a!=0)
        delta = b*b - 4*a*c;
    else
        printf("Jest to funkcja liniowa!\n"); return 0;

    if (delta > 0)
        printf("Rownanie ma dwa pierwiastki: x1 = %f, x2 = %f\n",
        (-b-sqrt(delta))/(2.*a) ,  (-b+sqrt(delta))/(2.*a) );
    else
        if (delta == 0)
            printf("Rownanie ma jeden pierwiastek x0 = %f\n", -b/(2.*a) );
        else
            if (delta < 0)
                printf("Brak miejsc zerowych!\n");


    /*Program nie wyswietla miejsc zerowych*/

}


float Zad5_6(float a, float b, float c)
{
    float p;

    if ( (a+b)>c && (a+c)>b && (b+c)>a )
        {
            p = (a+b+c)/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }

    else return 0;
}



void Zad5_7(int miesiac)
{
    printf("Podaj numer miesiaca: ");
    scanf("%d", &miesiac);

    switch (miesiac) {
    case 1:
    case 2:
    case 3:  printf("Pierwszy kwartal\n");  break;
    case 4:
    case 5:
    case 6:  printf("Drugi kwartal\n");  break;
    case 7:
    case 8:
    case 9:  printf("Trzeci kwartal\n");  break;
    case 10:
    case 11:
    case 12:  printf("Czwarty kwartal\n");  break;
    default:  printf("Zly numer miesiaca\n");  break;
    }

    switch (miesiac) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:  printf("Miesiac ma 31 dni\n");  break;
    case 4:
    case 6:
    case 9:
    case 11:  printf("Miesiac ma 30 dni\n");  break;
    case 2:  printf("Miesiac ma 28 lub 29 dni (Luty)\n");  break;
    default:  printf("Zly numer miesiaca\n");  break;
    }
}


void Zad5_8(int bilet, int n1, int n2, int n3, int n4, int n5, int n6)
{
    int suma1, suma2;

    n1 = bilet/100000;
    n2 = bilet/10000 - n1*10;
    n3 = bilet/1000 - n1*100 - n2*10;
    n4 = bilet/100 - n1*1000 - n2*100 - n3*10;
    n5 = bilet/10 - n1*10000 - n2*1000 - n3*100 - n4*10;
    n6 = bilet%10;

    suma1 = n1 + n2 + n3;
    suma2 = n4 + n5 + n6;

    if (suma1 == suma2)
        printf("Gratulacje! Twoj bilet jest szczesliwy!\n");
    else
        printf("Niestety, twoj bilet nie jest szczesliwy.\n");
}
