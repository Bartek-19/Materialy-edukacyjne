#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, i, j, k=1, Xmin, Xmax;
    double punkt;

    do{
        cout<<"Podaj ilosc wezlow:  ";
        cin>>n;
    }while(n<=0);

    int wezly[n];
    double p[n][n];

    for(i=0; i<n; i++)
    {
        cout<<"X["<<i<<"]:  ";
        cin>>wezly[i];
    }

    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(wezly[i]==wezly[j])
            {
                cout<<"Wezly nie sa parami rozne"<<endl;
                exit(1);
            }

    Xmin = wezly[0];
    Xmax = wezly[0];
    for(i=1; i<n; i++)
    {
        if(wezly[i]>Xmax)
            Xmax = wezly[i];
        if(wezly[i]<Xmin)
            Xmin = wezly[i];
    }

    for(i=0; i<n; i++)
    {
        cout<<"Y["<<i<<"]:  ";
        cin>>p[i][0];
    }

    cout<<"P:  ";
    cin>>punkt;

    if(punkt<Xmin || punkt>Xmax)
    {
        cout<<"Punkt P nie nalezy do zakresu ["<<Xmin<<";"<<Xmax<<"]"<<endl;
        exit(1);
    }

    while(k<n)
    {
        j=0;
        while(j<n-k)
        {
            p[j][k] = ((punkt-wezly[j])*p[j+1][k-1]-(punkt-wezly[j+k])*p[j][k-1])/(wezly[j+k]-wezly[j]);
            j++;
        }
        k++;
    }

    cout<<endl;

    i=0;
    cout<<endl<<setw(5+8*n)<<setfill('-')<<""<<endl;
    cout<<setfill(' ');
    for(j=0; j<n; j++)
    {
        cout<<setw(4)<<wezly[i++]<<"|";
        for(k=0; k<n-j; k++)
            cout<<setw(7)<<fixed<<setprecision(3)<<p[j][k]<<"|";
        for(k=n-j; k<n; k++)
            cout<<setw(7)<<" "<<"|";
        cout<<endl<<setw(5+8*n)<<setfill('-')<<""<<endl;
        cout<<setfill(' ');
    }
    cout<<endl<<"Wynik = "<<p[0][n-1]<<endl;

    return 0;
}
