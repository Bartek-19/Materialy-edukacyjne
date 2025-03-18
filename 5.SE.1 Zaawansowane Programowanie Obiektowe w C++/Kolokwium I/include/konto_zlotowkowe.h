#ifndef KONTO_ZLOTOWKOWE_H
#define KONTO_ZLOTOWKOWE_H

class konto_zlotowkowe
{
    public:
        konto_zlotowkowe(int nr, float s);
        virtual float przelicz() = 0;
        virtual void print();

    protected:
        int numer_konta;
        float saldo;
};

#endif // KONTO_ZLOTOWKOWE_H
