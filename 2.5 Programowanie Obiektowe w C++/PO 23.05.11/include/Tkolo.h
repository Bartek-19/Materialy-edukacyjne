#ifndef TKOLO_H
#define TKOLO_H

class Tpunkt;

class Tkolo
{
    public:
        Tkolo(float Ar);
        float getR();
        virtual ~Tkolo();
        friend bool nalezy(Tpunkt &P, Tkolo &K);

    private:
        float r;
};

#endif // TKOLO_H
