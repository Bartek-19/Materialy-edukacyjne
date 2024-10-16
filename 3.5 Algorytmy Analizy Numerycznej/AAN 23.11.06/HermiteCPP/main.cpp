#include <iostream>
#include <iomanip>

using namespace std;

int silnia(int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return n*silnia(n-1);
}

bool czySilnia(int xPocz, int xKonc)
{
    if(xPocz==xKonc)
        return true;
    else
        return false;
}

int main()
{
    int n, k=0, Kmax, i, j, stop, licznik;

    do{
        cout<<"Podaj ilosc wezlow:  ";
        cin>>n;
    }while(n<=0);

    int X[n];
    int K[n];

    for(i=0; i<n; i++)
    {
        cout<<"X["<<i<<"] = ";
        cin>>X[i];
    }
    for(i=0; i<n-1; i++)
    {
        if(X[i+1]<=X[i])
        {
            cout<<"Wezly nie spelniaja zalozenia"<<endl;
            exit(1);
        }
    }

    for(i=0; i<n; i++)
    {
        cout<<"K["<<i<<"] = ";
        cin>>K[i];
        if(K[i]<1)
        {
            cout<<"K["<<i<<"] nie spelnia zalozenia"<<endl;
            exit(1);
        }
    }

    Kmax = K[0];
    for(i=0; i<n; i++)
        Kmax = max(Kmax, K[i]);

    int F[Kmax][n];
    for(i=0; i<n; i++)
    {
        for(int j=0; j<K[i]; j++)
        {
            cout<<"f("<<j<<")[x"<<i<<"] = ";
            cin>>F[j][i];
        }
    }

    for(i=0; i<n; i++)
    {
        k+=K[i];
    }

    int Z[k];

    i = 0;
    j = 0;
    while(i<n)
    {
        stop = j+K[i];
        while(j<stop)
        {
            Z[j] = X[i];
            j++;
        }
        i++;
    }

    double IR[k][k];

    j=0;
    for(i=0; i<n; i++)
    {
        stop = j+K[i];
        while(j<stop)
        {
            IR[j][0] = F[0][i];
            j++;
        }
    }

    for(i=1; i<k; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(czySilnia(Z[i-j], Z[i]))
            {
                for(int m=0; m<n; m++)
                    if(X[m]==Z[i])
                        licznik = F[j][m];
                IR[i][j] = licznik/silnia(i);
            }
            else
                IR[i][j] = (IR[i][j-1]-IR[i-1][j-1])/(Z[i]-Z[i-j]);
        }
    }

    cout<<endl;
    for(i=0; i<k; i++)
    {
        for(j=0; j<=i; j++)
        {
            cout<<setw(8)<<IR[i][j]<<"|";
        }
        while(j<k)
        {
            cout<<setw(9)<<"|";
            j++;
        }
        cout<<endl;
    }
    cout<<endl;


    system("PAUSE");
    return 0;
}
