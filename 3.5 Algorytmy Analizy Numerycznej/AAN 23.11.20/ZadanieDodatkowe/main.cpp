#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m;
    double h, x, calka=0;

    cout<<"Calka (0->4)(x*e^2x dx)"<<endl<<endl;
    do{
        cout<<"Podaj m:  ";
        cin>>m;
    }while(m<=0);

    if(m%3!=0)
    {
        cout<<"Liczba podprzedzialow jest niepodzielna przez 3"<<endl;
        exit(1);
    }

    h = 4.0/m;

    double X[m+1], F[m+1];

    X[0] = 0;
    for(int i=1; i<=m; i++)
        X[i] = X[i-1] + h;

    for(int i=0; i<=m; i++)
    {
        x = X[i];
        F[i] = x * exp(2*x);
    }

    calka += F[0];
    for(int i=1; i<m; i++)
    {
        if(i%3==0)
            calka += 2*F[i];
        else
            calka += 3*F[i];
    }
    calka += F[m];
    calka *= (3*h)/8;

    cout<<"Wynik podanej calki to: "<<calka<<endl<<endl;

    exit(0);
    return 0;
}
