#ifndef TABLICEDYN_H_INCLUDED
#define TABLICEDYN_H_INCLUDED

float * utworzTD(int n);

void wyswietlTD(float * tabD, int n);

void usunTD(float *tabD);

float ** utworzT2D(int n, int m);

void wyswietlT2D(float**tab2D,int n, int m);

void losuj(int * tab, int n);

int * nowatabDyn(int* tab, int n, int a, int b, int* m);

void wyswietlTEST(int * tabD, int * n);

#endif // TABLICEDYN_H_INCLUDED
