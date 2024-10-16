#include <iostream>
#include "Tdomownik.h"
#include "Tsasiad.h"
#include "Tkolo.h"
#include "Tpunkt.h"
#include <cmath>

using namespace std;

void sasiad(Tdomownik &D)
{
    D.setKod();
    cout<<"Sekret "<<D.nazwa<<": "<<D.sekret<<endl;
}

bool nalezy(Tpunkt &P, Tkolo &K)
{
    if( sqrt(P.x*P.x + P.y*P.y) <= K.r )
        return true;
    else
        return false;
}

void nalezyPublic(Tpunkt &P, Tkolo &K)
{
    char odpowiedz;
    float x, y;

    while( sqrt(pow(P.getx(),2) + pow(P.gety(),2)) > K.getR() && odpowiedz!='N'){
        cout<<"Punkt nie nalezy do Kola"<<endl;

        do{
            cout<<"Czy chcesz przemiescic punkt w ukladzie wspolrzednych? (T/N):  ";
            cin>>odpowiedz;
        } while(odpowiedz!='T' && odpowiedz!='N');

        if(odpowiedz=='T')
        {
            cout<<"Podaj wspolrzedne wektora przemieszczenia:"<<endl;
            cin>>x>>y;
            P.ruch(x, y);
        }
    }

    if(sqrt(pow(P.getx(),2) + pow(P.gety(),2)) <= K.getR())
        cout<<"Punkt nalezy do Kola"<<endl;
}

int main()
{
    Tdomownik ojciec("Ojciec", "Chrapie w nocy"), matka("Matka", "Udostepnila dom sasiadowi"), corka("Corka", "Wagaruje");
    Tsasiad somsiad(matka);
    float R, X, Y, dX, dY;
    char wybor;

    cout<<"> Zadanie 1"<<endl<<endl;

    cout<<"Domownicy:"<<endl;
    ojciec.wyswietl();
    matka.wyswietl();
    corka.wyswietl();

    cout<<endl<<"Sasiad:"<<endl;
    somsiad.info(matka);
    sasiad(ojciec);

    //--------------------------

    cout<<endl<<endl<<"> Zadanie 2"<<endl<<endl;

    do{
        cout<<"Podaj promien kola o srodku w punkcie (0,0):  ";
        cin>>R;
    } while(R <= 0);

    cout<<"Podaj wspolrzedne punktu na plaszczyznie kartezjanskiej:"<<endl;
    cin>>X>>Y;

    Tkolo koleczko(R);
    Tpunkt punkcik(X, Y);

    cout<<endl<<"> Porownywanie polozenia punktu wzgledem kola"<<endl<<endl;
    cout<<"Wersja z funkcja zaprzyjazniona"<<endl;
    cout<<"Promien:  "<<koleczko.getR()<<endl<<"x = "<<punkcik.getx()<<endl<<"y = "<<punkcik.gety()<<endl<<endl;

    while(wybor!='N' && nalezy(punkcik, koleczko)==false){
            cout<<"Punkt nie nalezy do kola"<<endl;
            do{
                cout<<"Czy chcesz przemiescic punkt w ukladzie wspolrzednych? (T/N):  ";
                cin>>wybor;
            } while(wybor!='T' && wybor!='N');
            if(wybor=='T')
            {
                cout<<"Podaj wspolrzedne wektora przemieszczenia:"<<endl;
                cin>>dX>>dY;
                punkcik.ruch(dX, dY);
            }
    }

    if(nalezy(punkcik, koleczko))
        cout<<"Punkt nalezy do Kola"<<endl;

    cout<<endl<<"Wspolrzedne punktu po przemieszczeniach"<<endl;
    cout<<"x = "<<punkcik.getx()<<endl<<"y = "<<punkcik.gety()<<endl<<endl;

    punkcik.ruch(X-punkcik.getx(), Y-punkcik.gety()); //Reset polozenia punktu
    cout<<" ----------"<<endl;

    cout<<"Wersja z funkcja zwykla"<<endl;
    cout<<"Promien:  "<<koleczko.getR()<<endl<<"x = "<<punkcik.getx()<<endl<<"y = "<<punkcik.gety()<<endl<<endl;
    nalezyPublic(punkcik, koleczko);
    cout<<endl<<"Wspolrzedne punktu po przemieszczeniach"<<endl;
    cout<<"x = "<<punkcik.getx()<<endl<<"y = "<<punkcik.gety()<<endl<<endl;

    return 0;
}
