#ifndef MAXBUFOR_H
#define MAXBUFOR_H

#include <Bufor.h>


class MaxBufor : public Bufor
{
    public:
        MaxBufor();
        MaxBufor(int N);
        virtual ~MaxBufor();
        virtual double calculate() override;
        virtual void add(int value) override;
};

#endif // MAXBUFOR_H
