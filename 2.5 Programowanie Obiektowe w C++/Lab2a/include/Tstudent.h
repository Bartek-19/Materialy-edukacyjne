#ifndef TSTUDENT_H
#define TSTUDENT_H

class Tstudent
{
public:
    void wczytaj();
    float sredniaOcen();
    void wyswietl();
    bool czyZdal();
private:
    char imie[20], nazwisko[30];
    float oceny[3];
    float srednia;
    bool zdal;
};

#endif // TSTUDENT_H
