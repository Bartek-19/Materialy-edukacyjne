#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
    private:
        float area, circumference;
    public:
        Figure();
        virtual ~Figure();
        float getArea();
        void setArea(float area1);
        float getCircumference();
        void setCircumference(float circ);
        virtual void calculateArea()=0;
        virtual void calculateCircumference()=0;
        void show();
};

#endif // FIGURE_H
