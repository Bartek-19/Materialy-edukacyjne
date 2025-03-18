#include <iostream>
#include "Figure.h"

using namespace std;

Figure::Figure()
{
    cout<<"Konstruktor klasy bazowej Figure"<<endl;
}

Figure:: ~Figure()
{
    cout<<"Wirtualny destruktor klasy bazowej Figure"<<endl;
}

float Figure:: getArea()
{
    return area;
}

void Figure::setArea(float area1)
{
    area=area1;
}

float Figure::getCircumference()
{
    return circumference;
}

void Figure::setCircumference(float circ)
{
    circumference = circ;
}

void Figure::show()
{
    cout<<"Pole: "<<area<<endl<<"Obwod: "<<circumference<<endl;
}
