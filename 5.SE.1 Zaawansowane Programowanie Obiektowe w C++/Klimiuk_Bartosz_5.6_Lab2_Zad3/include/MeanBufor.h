#ifndef MEANBUFOR_H
#define MEANBUFOR_H

#include <Bufor.h>


class MeanBufor : public Bufor
{
    public:
        MeanBufor();
        MeanBufor(int N);
        virtual ~MeanBufor();
        virtual double calculate() override;
};

#endif // MEANBUFOR_H
