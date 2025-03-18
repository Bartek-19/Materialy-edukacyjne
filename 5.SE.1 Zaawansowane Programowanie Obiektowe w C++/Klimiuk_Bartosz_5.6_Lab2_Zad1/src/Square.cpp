#include <iostream>
#include "Square.h"
#include "Figure.h"

using namespace std;

Square:: Square(float a1):Figure()
{
    a=a1;
    cout<<"Konstruktor klasy Square"<<endl;
}

Square:: ~Square()
{
    cout<<"Destruktor klasy Square"<<endl;
}

void Square::calculateArea()
{
    float p = a*a;
    setArea(p);
}

void Square::calculateCircumference()
{
    float obw = 4*a;
    setCircumference(obw);
}
