#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, i, j;
    char upewnijSie;
    double temp;

    do{
        cout<<"Podaj wymiar macierzy A:  ";
        cin>>n;
    } while(n<=0);

    //Alokacja macierzy w pamieci
    double **A = new double*[n];
    for(i=0; i<n; i++)
        A[i] = new double[n];

    double **L = new double*[n];
    for(i=0; i<n; i++)
        A[i] = new double[n];

    double *B = new double[n];
    double *Y = new double[n];
    double *X = new double[n];

    //Wczytywanie danych
    cout<<endl<<"Wczytywanie danych do macierzy glownej:"<<endl;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            cout<<"A["<<i<<"]["<<j<<"]:  ";
            cin>>A[i][j];
        }

    cout<<endl<<"Wczytywanie danych do macierzy wyrazow wolnych:"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"B["<<i<<"]:  ";
        cin>>B[i];
    }
    cout<<endl;

    //Upewnienie sie o poprawnosci danych ze strony uzytkownika
    do {
        cout<<"Czy podane wartosci macierzy sa poprawne? (T/N):  ";
        cin>>upewnijSie;
        if(upewnijSie=='n' || upewnijSie=='N')
        {
            cout<<"Program nie zostanie wykonany poprawnie - koniec programu!"<<endl;
            for(i=0; i<n; i++)
                delete [] A[i];
            delete [] A;

            for(i=0; i<n; i++)
                delete [] L[i];
            delete [] L;

            delete [] B;
            exit(1);
        }
    } while(upewnijSie!='n' && upewnijSie!='N' && upewnijSie!='t' && upewnijSie!='T');

    //Uzupelnienie macierzy trojkatnej dolnej
    cout<<endl<<"Uzupelnienie macierzy trojkatnej dolnej"<<endl;
    for(i=0; i<n; i++)
        for(j=0; j<=i; j++)
        {
            if(j==i)
            {
                temp = A[i][j];
                for(int m=0; m<j; m++)
                    temp -= L[i][m]*L[i][m];
                L[i][j] = sqrt(temp);
            }
            else
            {
                temp = A[i][j];
                for(int m=0; m<j; m++)
                    temp -= L[i][m]*L[j][m];
                L[i][j] = temp/L[j][j];
            }
            cout<<"Wstawiono element L["<<i<<"]["<<j<<"]"<<endl;
        }

    //Uzupelnienie macierzy trojkatnej gornej
    cout<<endl<<"Uzupelnienie macierzy trojkatnej gornej"<<endl;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            L[i][j] = L[j][i];

    //Obliczenie elementow macierzy Y
    cout<<endl<<"Obliczenie elementow macierzy Y"<<endl;
    for(i=0; i<n; i++)
    {
        temp = 0;
        for(j=0; j<i; i++)
            temp -= Y[j]*L[i][j];
        temp += B[i];
        Y[i] = temp/L[i][i];
    }

    //Obliczanie elementow macierzy X - wynikowej
    cout<<endl<<"Obliczanie elementow macierzy X - wynikowej"<<endl;
    for(i=n-1; i>=0; i--)
    {
        temp = 0;
        for(j=i+1; j<n; j++)
            temp -= X[j]*L[i][j];
        temp += Y[i];
        X[i] = temp/L[i][i];
    }

    //Wyswietlanie macierzy
    cout<<"> Macierz A:"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"|";
        for(j=0; j<n; j++)
            cout<<setw(10)<<A[i][j];
        cout<<"|"<<endl;
    }

    cout<<endl<<"> Macierz B:"<<endl;
    for(i=0; i<n; i++)
        cout<<"|"<<setw(10)<<B[i]<<"|"<<endl;

    cout<<endl<<"> Macierz L:"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"|";
        for(j=0; j<n; j++)
            cout<<setw(10)<<L[i][j];
        cout<<"|"<<endl;
    }

    cout<<endl<<"> Macierz Y:"<<endl;
    for(i=0; i<n; i++)
        cout<<"|"<<setw(10)<<Y[i]<<"|"<<endl;

    cout<<endl<<"> Macierz X:"<<endl;
    for(i=0; i<n; i++)
        cout<<"|"<<setw(10)<<X[i]<<"|"<<endl;

    //Usuwanie macierzy z pamieci
    for(i=0; i<n; i++)
        delete [] A[i];
    delete [] A;

    for(i=0; i<n; i++)
        delete [] L[i];
    delete [] L;

    delete [] B;

    cout<<endl;
    exit(0);
    return 0;
}
