#ifndef USER_H
#define USER_H
#include <QString>


enum class Sex
{
    male,
    female,
    unset
};

struct User
{
    QString name;
    int typeOfTraining=0;
    int age;
    int weight;
    int height;
    Sex sex=Sex::unset;

};

#endif // USER_H
