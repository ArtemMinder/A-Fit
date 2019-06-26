#ifndef USER_H
#define USER_H
#include <QString>


enum class Sex
{
    male,
    female
};

struct User
{
    QString name;
    int typeOfTraining;
    int age;
    int weight;
    int height;
    Sex sex;

};

#endif // USER_H
