#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>

using namespace std;

class Contact
{
public:
    string imie;
    string nazwisko;
    int wiek;
    string numerTelefonu;
    string ulica;
    void show();

    Contact(string imie, string nazwisko, int wiek, string numerTelefonu, string ulica)
        : imie(imie), nazwisko(nazwisko), wiek(wiek), numerTelefonu(numerTelefonu), ulica(ulica) {}

    void show() const {
        cout << numerTelefonu << " - " << nazwisko << ", " << imie << ", wiek: " << wiek << ", ulica: " << ulica << endl;
    }
};

#endif // CONTACT_H
