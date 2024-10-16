#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void przerwa(){
	printf("\n");
	printf("|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|\n");
	printf("\n");
}

void zadanie3_8(){
    double x1, x2, a, b, wyn1, wyn2, wyn3, wyn4, rad1, rad2, rad3, rad4;
    double cos(double x1);
    double sin(double x1);
    double log(double x2);
    double exp(double x2);
    double dabs(double tan(double x2));           /*Problemy z potegami*/
    double sin(double a);
    double cos(double a);
    double tan(double a);
    double dabs(double sin (double b));
    double sin(double b);
    double cos(double b);

    printf("Podaj miare kata (w radianach): "); scanf("%f", &x1);
    
    rad1=M_PI*x1/180;
    
    wyn1=10*cos(rad1)-01*rad1*rad1+sin(rad1)+sqrt(4*rad1*rad1-7);
    
	printf("Pierwszy wynik = %.2f\n", wyn1);			/*Konsola nie pokazuje wyniku*/
    
	printf("\n");
    
	printf("Podaj miare kata (w radianach): "); scanf("%f", &x2);
	
	rad2=M_PI*x2/180;
	
	wyn2=log(rad2+5)/log(10)+exp(rad2+1)-abs(tan(rad2)+1);
	
	printf("Drugi wynik = %.2f\n", wyn2);
	
	printf("\n");
	
	printf("Podaj miare kata (w radianach): "); scanf("%f", &a);
	
	rad3=M_PI*a/180;
	
	wyn3=(sin(rad3)*sin(rad3)-0.5)/(cos(rad3*rad3*rad3*rad3)+tan(rad3*rad3)*tan(rad3*rad3)*tan(rad3*rad3)*tan(rad3*rad3));
	
	printf("Trzeci wynik = %.2f\n", wyn3);
	
	printf("\n");
	
	printf("Podaj miare kata (w radianach): "); scanf("%f", &b);
	
	rad4=M_PI*b/180;
	
	wyn4=sqrt((abs(5*sin(rad4*rad4*rad4*rad4*rad4)+1))/(3.5*(sin(rad4)+cos(rad4))*(sin(rad4)+cos(rad4))));
	
	printf("Czwarty wynik = %.2f\n", wyn4);
	
	printf("\n");
}

void zadanie3_9(){
	double x, rad, sinus, cosinus, tangens;
	double sin(double x);
	double cos(double x);
	double tan(double x);
	
	printf("Podaj miare kata (w stopniach): "); scanf("%f", &x);
	
	rad=M_PI*x/180;
	
	sinus=sin(rad);
	cosinus=cos(rad);
	tangens=tan(rad);
	
	printf("Sinus tego kata wynosi %.2f, cosinus %.2f, tangens %.2f\n", sinus, cosinus, tangens);
}

void zadanie3_10(){
	int a, a1, a2, a3, aswitch, b, b1, b2, b3, bswitch;
	
	printf("Podaj liczbe trzycyfrowa: \n"); scanf("%d", &a);
	
	printf("Podaj druga liczbe calkowita: \n"); scanf("%d", &b);
	
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
	
	printf("a po zamianie = %d, b po zamianie = %d", aswitch, bswitch);\
}

void zadanie3_11(){
	float x1, x2, y1, y2, r, obw;
	
	printf("Podaj wspolrzedne punktu znajdujacego sie na okregu: "); scanf("%f %f", &x1, &y1);
	printf("Podaj wspolrzedne srodka okregu: "); scanf("%f %f", &x2, &y2);
	printf("\n");
	
	r=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	obw=r*M_PI;
	
	printf("Obwod tego okregu wynosi %.2f", obw);
}
int main()
{
    zadanie3_8();
    przerwa();
    
    zadanie3_9();
	przerwa();
	
  	zadanie3_10();
	przerwa();
	
	zadanie3_11();
	przerwa();
		
    system("PAUSE");
    return 0;
}
