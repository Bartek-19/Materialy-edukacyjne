#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string surname, int age, int experience, int salary);
        virtual ~Employee();

        virtual void show();
        virtual float calculateBonus(int value) = 0;
        int ageEmployment();

        void setSurname(string surname);
        void setAge(int age);
        void setExperience(int exp);
        void setSalary(float salary);

        string getSurname();
        int getAge();
        int getExperience();
        float getSalary();

    private:
        string surname;
        int age;
        int experience;
        float salary;
};

#endif // EMPLOYEE_H
