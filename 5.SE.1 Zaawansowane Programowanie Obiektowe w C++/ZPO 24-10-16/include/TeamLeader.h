#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <Employee.h>


class TeamLeader : public Employee
{
    public:
        TeamLeader();
        TeamLeader(string surname, int age, int experience, int salary);
        ~TeamLeader();
        float calculateBonus(int value);
        void show();
};

#endif // TEAMLEADER_H
