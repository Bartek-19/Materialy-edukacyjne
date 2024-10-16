#include <stdlib.h>
#include <stdio.h>

float *utworzTD(int n)
{
    int i;
    float *tabD = (float*) malloc (n *sizeof(float));

    if(tabD==NULL)
        {
        printf("Blad przydzialu pamieci\n");
        exit(EXIT_FAILURE);
        }

    for (i=0; i<n; i++)
        {
        printf("wpisz liczbe tab[%d]: ", i);
        scanf("%f", tabD + i);
        }

    return tabD;
}


void wyswietlTD(float * tabD, int n)
{
    int i;

    printf ("\nZawartosc tablicy:\n");

    for (i=0; i<n; i++)
        printf ("%8.3f\n", *(tabD+i));

    printf ("\n ");
}


void usunTD(float *tabD)
{
    free(tabD);
    tabD=0;
}


float ** utworzT2D(int n, int m)
{
    float**tab2D;
    int i,j;

    tab2D = (float**) malloc(sizeof(float *)*n);

    if(tab2D==NULL)
        {
            printf("Blad przydzialu pamieci\n");
            exit(EXIT_FAILURE);
        }

    for(i=0; i < n; i++)
    {
        tab2D[i] = (float*) malloc(sizeof(float)*m);
        if(tab2D[i]==NULL)
        {
            printf("Blad przydzialu pamieci\n");
            exit(EXIT_FAILURE);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            // *(*(tab2D+i)+j)=i*j;
            printf("tab[%d][%d]= ", i,j);
            scanf("%f", *(tab2D+i)+j);
        }
    }

    return tab2D;
}


void wyswietlT2D(float**tab2D,int n, int m)
{
    int i,j;
    printf("Tablica dynamiczna 2D\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%8.3f\n",*(*(tab2D+i)+j));
        }
    printf("\n");
    }
}


void losuj(int * tab, int n)
{
    int i;

    for (i=0; i<n; i++)
    {
        *tab = rand() % 100 + 1;
    }
}


int * nowatabDyn(int* tab, int n, int a, int b, int* m)
{
    int i, j=0;

    for (i=0; i<n; i++)
    {
        if (*tab>a && *tab<b)
        {
            *m++;
        }
        tab++;
    }

    int tablica[*m];

    for (i=0; i<n; i++)
    {
        if (*tab>a && *tab<b)
        {
            tablica[j] = *tab;
            j++;
        }
        tab++;
    }

    return (int *) tablica;
}


void wyswietlTEST(int * tabD, int * m)
{
    int i;

    printf ("\nZawartosc tablicy:\n");

    for (i=0; i<*m; i++)
        printf ("%8.3d\n", *(tabD+i));

    printf ("\n ");
}

