#include "Developer.h"

#include <iostream>
using namespace std;

Developer::Developer()
{
    //cout<<"Zatrudniono developera"<<endl<<endl;
}

Developer::Developer(string surname, int age, int experience, int salary)
{
    setSurname(surname);
    setAge(age);
    setExperience(experience);
    setSalary(salary);
}

Developer::~Developer()
{
    //cout<<"Zwolniono developera"<<endl<<endl;
}

float Developer::calculateBonus(int value)
{
    return value + 0.2 * value * (getSalary() + getExperience());
}

void Developer::show()
{
    cout<<"Nazywam sie "<<getSurname()<<", mam "<<getAge()<<"lat,"<<endl;
    cout<<"Jestem developerem z "<<getExperience()<<" letnim doœwiadczeniem, zarabiam "<<getSalary()+calculateBonus(getExperience())<<" zl"<<endl;
}
