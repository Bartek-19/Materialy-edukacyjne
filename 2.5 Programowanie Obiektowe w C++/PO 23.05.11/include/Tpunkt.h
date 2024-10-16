#ifndef TPUNKT_H
#define TPUNKT_H

class Tkolo;

class Tpunkt
{
    public:
        Tpunkt(float Ax, float Ay);
        void ruch(float dx, float dy);
        float getx();
        float gety();
        virtual ~Tpunkt();
        friend bool nalezy(Tpunkt &P, Tkolo &K);

    protected:
        float x, y;

    private:
};

#endif // TPUNKT_H
