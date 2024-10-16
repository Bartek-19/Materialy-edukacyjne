#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void srednia1(int a, int b);
void przerywnik ();
float f1(float x);
float f3(float alfa);
void zadanie1(char imie[30]);
void zadanie2(int a, int a1, int a2, int a3, int b, int b1, int b2, int b3, int aswitch, int bswitch);
void zaadnie3();
void zadanie5_3(int t, float z, float alfa2);
float funkcja1(int t, float z, float alfa2);
void funkcja2(int t, float z, float alfa2);


int main()
{
/*    int a, b;
    printf("Podaj liczby: \n");
    scanf("%d %d", &a, &b);

    srednia1(a, b);

    przerywnik();

    float x;

    printf("Zadanie 4_8\n");

    przerywnik();

    printf("Podaj x: ");
    scanf("%f", &x);
    printf("wynik: %0.2f\n", f1(x));

    przerywnik();

    float alfa;

    printf("Podaj alfa: ");
    scanf("%f", &alfa);
    printf("wynik: %0.2f\n", f3(alfa));

    przerywnik();
	
	printf("Zadanie 1.\n");
    
    przerywnik();
    
    char imie[30];
    
    printf("Podaj swoje imie: \n");
	scanf("%s", &imie);
    
    zadanie1(imie);
    
    przerywnik();
    
    printf("Zadanie 4_10\n");
    
    przerywnik();
    
    int a1, a2, a3, b1, b2, b3, aswitch, bswitch;
    
    printf("Podaj liczbe trzycyfrowa: \n");
    scanf("%d", &a);
    
    printf("podaj druga liczbe: \n");
    scanf("%d", &b);
    
    zadanie2(a, a1, a2, a3, b, b1, b2, b3, aswitch, bswitch);
*/
	przerywnik();
	
	int t;
	float z, alfa2;
	
	printf("Zadanie 5_3\n");
	
	przerywnik();
	
	zadanie5_3(t, z, alfa2);
	
	przerywnik();
	
	funkcja1(t, z, alfa2);
	
	przerywnik();
	
	
	
	
    system("PAUSE");
    return 0;
}


void przerywnik(){
    printf("\n");
    printf("//////////////////////\n");
    printf("\n");
}


void srednia1(int a, int b){
    printf("Srednia: %0.2f\n", (float)(a+b)/2 );
}


float f1(float x){
    return 10*cos(x)-0.1*pow(x, 2)+sin(x)+sqrt(4*pow(x, 2)+7);
}


float f3(float alfa){
    return  (pow (sin(alfa), 2) + 0.5)  /  (cos(pow(alfa, 4)) + pow (tan(pow(alfa, 2)), 4) );
}


void zadanie1(char imie[30]){
/* Zadanie 'Ile liter ma twoje imie?' */	
    
	printf("Twoje imie ma %d liter\n", strlen(imie));
}


void zadanie2(int a, int a1, int a2, int a3, int b, int b1, int b2, int b3, int aswitch, int bswitch){
/* Zadanie 4.10 */

	printf("a = %d, b = %d", a, b);

	printf("\n");

	a1=a/100;
	a2=(a-a1*100)/10;
	a3=a%10;

	aswitch=a3*100+a2*10+a1;

	b1=b/100;
	b2=(b-b1*100)/10;
	b3=b%10;

	bswitch=b3*100+b2*10+b1;
	    
    printf("a po zamianie = %d, b po zamianie = %d", aswitch, bswitch);
	
	printf("\n");
}


void zadanie3(){
/* Zadanie 4.12 */
}


void zadanie5_3(int t, float z, float alfa2){
    

    printf("Podaj alfa: \n");
    scanf("%f", &alfa2);

    printf("Podaj t: \n");
    scanf("%d", &t);
        

}

float funkcja1(int t, float alfa2, float z){
	
	if(t==8)
        { z = 1-sin(alfa2); }
    else if(0<=t<=3)
        { z = 0.5*(1+cos(alfa2)); }
    else if(4<=t<=7)
    	{ z = sqrt( pow(alfa2, 2) + 1 ); }
    
	printf("%f\n", z);

}
