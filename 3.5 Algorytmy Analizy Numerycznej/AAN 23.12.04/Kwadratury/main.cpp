#include <iostream>
#include <cmath>
#define M_Pi 3.14159

using namespace std;

int main()
{
    int n, wybor;
    double calka  = 0;

    cout<<"Wybierz calke"<<endl;
    cout<<"1. (-1->1)((x^2 dx) / sqrt(1-x^2))       metoda Gaussa-Czebyszewa    n=3"<<endl;
    cout<<"2. (-1->1)(dx / sqrt(1+x^2))             metoda Gaussa-Legendra      n=4"<<endl;
    cout<<"3. (0->inf)(e^-x * e^-x * sin(x)/x dx)   metoda Gaussa-Laguerra      n=3"<<endl;
    cout<<"4. (-inf->inf)(e^(-(x^2)) * cos(x) dx)   metoda Gaussa-Hermita       n=4"<<endl;

    do{
        cout<<"Podaj swoj wybor:  ";
        cin>>wybor;
    }while(wybor<1 || wybor>4);

    if(wybor==1) {
        n = 3;
        double X[n+1], H[n+1];
        for(int i=0; i<=n; i++)
        {
            H[i] = M_Pi/(n+1);
            X[i] = cos(((2*i+1)*M_Pi)/(2*(n+1)));
        }
        for(int i=0; i<=n; i++)
            calka += H[i]*pow(X[i],2);
    } else if(wybor==2) {
        n = 4;
        double X[n+1] = {-0.906180, -0.538469, 0, 0.538469, 0.906180},
               H[n+1] = {0.236927, 0.478629, 0.568889, 0.478629, 0.236927};
        for(int i=0; i<=n; i++)
            calka += H[i]/sqrt(1+pow(X[i], 2));
    } else if(wybor==3) {
        n = 3;
        double X[n+1] = {0.322548, 1.745761, 4.536620, 9.395071},
               H[n+1] = {0.603154, 0.357419, 0.038888, 0.000539};
        for(int i=0; i<=n; i++)
            calka += H[i]*exp(-X[i])*(sin(X[i])/X[i]);
    } else if(wybor==4) {
        n = 4;
        double X[n+1] = {-2.020183, -0.958572, 0, 0.958572, 2.020183},
               H[n+1] = {0.019953, 0.393619, 0.945309, 0.393619, 0.019953};
        for(int i=0; i<=n; i++)
            calka += H[i]*cos(X[i]);
    } else {
        cout<<"Blad programu"<<endl;
        exit(1);
    }

    cout<<"Wnik calki:  "<<calka<<endl;

    cout<<endl;
    return 0;
}
