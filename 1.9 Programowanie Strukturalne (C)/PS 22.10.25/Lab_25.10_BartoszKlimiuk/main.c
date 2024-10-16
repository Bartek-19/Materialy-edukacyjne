#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STATUS "student"
#define SREDNIA (5)

void zadanie3_3(){
    char *plec;
    char imie[17] = "Bartosz", nazwisko[17] = "Klimiuk";
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
    scanf("%c", &plec);
    scanf("%s", &imie);
    scanf("%s", &nazwisko);
    printf("Plec: %c\t", plec);
    printf("Imie: %s\t", imie);
    printf("Nazwisko: %s\n", nazwisko);
    printf("Status: %s\t", STATUS);
    printf("Ocena: %d\n", SREDNIA);
}

void zadanie3_4(){
    const float PI = 3.14159;
    float r, a1, a2, h1, h2, p1, v1, p2, v2, p3, v3;
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
    printf("Podaj bok szescianu: \n"); scanf("%f", &a1);
    p1=6*a1*a1; v1=a1*a1*a1;
    printf("Pole powierzchni szescianu wynosi: %0.2f, natomiast objetosc wynosi: %0.2f\n", p1, v1);
    printf("-------------------------\n");
    printf("Podaj krawedz podstawy prostopadloscianu prawidlowego czworokatnego: \n"); scanf("%f", &a2);
    printf("Podaj jego wysokosc: \n"); scanf("%f", &h1);
    p2=2*a2*a2+4*a2*h1; v2=a2*a2*h1;
    printf("Pole powierzchni prostopadloscianu wynosi: %0.2f, a jego objetosc wynosi: %0.2f\n", p2, v2);
    printf("-------------------------\n");
    printf("Podaj promien podstawy walca: \n"); scanf("%f", &r);
    printf("podaj jego wysokosc: \n"); scanf("%f", &h2);
    p3=2*PI*r*r+2*PI*r*h2; v3=PI*r*r*h2;
    printf("Pole powierzchni walca wynosi: %0.2f, a jego objetosc jest rowna: %0.2f\n", p3, v3);
}

void zadanie3_5(){
    int x1, x2;
    double srednia1, srednia2;
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
    printf("Podaj pierwsza liczbe (calkowita): \n"); scanf("%d", &x1);
    printf("Podaj druga liczbe (calkowita): \n"); scanf("%d", &x2);
    srednia1=(x1+x2)/2.0; srednia2=sqrt(x1*x2)*1.0;
    printf("Srednia arytmetyczna tych liczb wynosi: %0.2f, ich srednia geometryczna wynosi: %0.2f\n", srednia1, srednia2);
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
}

void zadanie3_6(){
    float s1, s2, s3, s4, P1, P2, V1, V2, t1, t2;
    printf("Podaj odleglosc (w milach): \n"); scanf("%f", &s1);
    s2=s1/0.625; printf("Odleglosc ta jest rowna %0.2f kilometrow\n", s2);
    printf("--------------------\n");
    printf("Podaj odleglosc (w kilometrach): \n"); scanf("%f", &s3);
    s4=s3/1.6;
    printf("Ta odleglosc wynosi %0.2f mil ladowych\n", s4);
    printf("--------------------\n");
    printf("Podaj moc (w koniach mechanicznych): \n"); scanf("%f", &P1);
    P2=P1*0.735;
    printf("Ta moc jest rowna %0.2f kW\n", P2);
    printf("--------------------\n");
    printf("Poadaj predkosc (w km/h): \n"); scanf("%f", &V1);
    V2=V1/3.6;
    printf("Ta predkosc jest rowna %0.2f m/s\n", V2);
    printf("--------------------\n");
    printf("Podaj wartosc temperatury (w stopniach Fahrenheita): \n"); scanf("%f", &t1);
    t2=5.0/9.0*(t1-32);
    printf("Podana temperatura jest rowna %0.2f stopni Celsjusza\n", t2);
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
}

void zadanie3_7(){
    int mies, mies1, mies2, lata1, lata2;
    printf("Podaj swoj wiek w latach i miesiacach (ktore uplynely od twoich ostatnich urodzin): \n");
    scanf("%d", &lata1); scanf("%d", &mies1);
    printf("Podaj okres czasu (w miesiacach): \n");
    scanf("%d", &mies);
    lata2=lata1+mies/12;
    mies2=(mies1+mies)%12;
    printf("Za %d miesiecy bedziesz miec %d lat i %d miesiecy\n", mies, lata2, mies2);
    printf("=========================\n");
    printf("*************************\n");
    printf("=========================\n");
}

int main(int argc, char *argv[]){

    zadanie3_3();

    zadanie3_4();

    zadanie3_5();

    zadanie3_6();

    zadanie3_7();

    system("PAUSE");
    return 0;
}
