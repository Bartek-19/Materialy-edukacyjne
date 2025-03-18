#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <Employee.h>


class Developer : public Employee
{
    public:
        Developer();
        Developer(string surname, int age, int experience, int salary);
        ~Developer();
        float calculateBonus(int value);
        void show();
};

#endif // DEVELOPER_H
