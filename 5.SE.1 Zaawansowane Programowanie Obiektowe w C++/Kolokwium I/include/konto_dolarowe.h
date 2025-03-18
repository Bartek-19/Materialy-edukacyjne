#ifndef KONTO_DOLAROWE_H
#define KONTO_DOLAROWE_H

#include <konto_zlotowkowe.h>


class konto_dolarowe : public konto_zlotowkowe
{
    public:
        konto_dolarowe(int nr, float s, float k):konto_zlotowkowe(nr, s){kurs=k;};
        virtual float przelicz() override;
        virtual void print() override;

    private:
        float kurs = 4.4119;
};

#endif // KONTO_DOLAROWE_H
