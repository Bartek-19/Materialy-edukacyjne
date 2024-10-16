#include <iostream>
#include <iomanip>

using namespace std;

struct tData{
    int d, m, r;
};

//1. Zadeklaruj klase o okreslonych polach i metodach
class Tpracownik{
private:
    char imie[20], nazwisko[30];
    float stawka;
    int godziny;
    tData zatr;
public:
    void wczytaj();
    float wyplata();
    void wyswietl();
};

//2. Zdefinuj metody zadeklarowane w klasie

void Tpracownik::wczytaj()
{
    cout<<endl<<"Podaj imie:  ";
    cin>>imie;
    cout<<"Podaj nazwisko:  ";
    cin>>nazwisko;
    cout<<"Podaj stawke pracownika:  ";
    cin>>stawka;
    cout<<"Podaj ilosc godzin przepracowanych przez pracownika:  ";
    cin>>godziny;
    cout<<"Podaj date zatrudnienia (DD MM RRRR):"<<endl;
    cin>>zatr.d>>zatr.m>>zatr.r;
}

float Tpracownik::wyplata()
{
    return stawka*godziny;
}

void Tpracownik::wyswietl()
{
    cout<<"Imie:               "<<imie<<endl;
    cout<<"Nazwisko:           "<<nazwisko<<endl;
    cout<<"Wyplata:            "<<fixed<<setprecision(2)<<wyplata()<<" zl."<<endl;
    cout<<"Data zatrudnienia:  "<<zatr.d<<"."<<zatr.m<<"."<<zatr.r<<" r."<<endl<<endl;
}


int main()
{
    //3. Zadeklaruj obiekt danej klasy
    Tpracownik pracownik1, pracownik2;

    //4. Zywolaj metody dla obiektu
    cout<<"Pracownik 1"<<endl<<endl;
    pracownik1.wczytaj();

    cout<<"Pracownik 2"<<endl<<endl;
    pracownik2.wczytaj();

    pracownik1.wyswietl();
    pracownik2.wyswietl();

    return 0;
}
