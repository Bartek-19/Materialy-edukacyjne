#include<iostream>
#include "Figure.h"
#include "Circle.h"
using namespace std;

Circle::Circle(float r1)
{
    r=r1;
    cout<<"Konstruktor w klasie Circle"<<endl;
}

Circle::~Circle()
{
    cout<<"Destruktor w klasie Circle"<<endl;
}

void Circle:: calculateArea()
{
    float p = 3.14*r*r;
    setArea(p);
}

void Circle::calculateCircumference()
{
    float obw = 2*3.14*r;
    setCircumference(obw);
}
