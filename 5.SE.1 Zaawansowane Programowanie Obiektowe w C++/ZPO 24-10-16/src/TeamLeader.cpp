#include "TeamLeader.h"

TeamLeader::TeamLeader()
{
    //ctor
}

TeamLeader::TeamLeader(string surname, int age, int experience, int salary)
{
    setSurname(surname);
    setAge(age);
    setExperience(experience);
    setSalary(salary);
}

TeamLeader::~TeamLeader()
{
    //dtor
}

float TeamLeader::calculateBonus(int value)
{
    return value * (1 + getSalary() + getExperience());
}

void TeamLeader::show()
{
    cout<<"Nazywam sie "<<getSurname()<<", mam "<<getAge()<<"lat,"<<endl;
    cout<<"Jestem Team Leaderem z "<<getExperience()<<" letnim doœwiadczeniem, zarabiam "<<getSalary()+calculateBonus(getExperience())<<" zl"<<endl<<endl;
}
