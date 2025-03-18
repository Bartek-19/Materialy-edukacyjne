#include "Employee.h"

#include <iostream>
using namespace std;

Employee::Employee()
{
    //ctor
}

Employee::Employee(string surname, int age, int experience, int salary)
{
    setSurname(surname);
    setAge(age);
    setExperience(experience);
    setSalary(salary);
}

Employee::~Employee()
{
    //dtor
}

void Employee::show()
{
    cout<<"> Nazwisko: "<<surname<<endl;
    cout<<"> Wiek: "<<age<<endl;
    cout<<"> Doswiadczenie: "<<experience<<endl;
    cout<<"> Wyplata: "<<salary<<endl;
}

int Employee::ageEmployment()
{
    return age-experience;
}

void Employee::setSurname(string surname)
{
    this->surname = surname;
}

void Employee::setAge(int age)
{
    this->age = age;
}

void Employee::setExperience(int exp)
{
    experience = exp;
}

void Employee::setSalary(float salary)
{
    this->salary = salary;
}

string Employee::getSurname()
{
    return surname;
}

int Employee::getAge()
{
    return age;
}

int Employee::getExperience()
{
    return experience;
}

float Employee::getSalary()
{
    return salary;
}
