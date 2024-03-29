#ifndef LOGIC_H
#define LOGIC_H


#include "user.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QMessageBox>
#include <QFile>
#include <QVector>
#include "training.h"


class Logic
{
public:
 Logic();

void saveUser(const User& user);
QString warmUP(int typeOfTrain);
QString biceps(int typeOfTrain);
QString chest(int typeOfTrain);
QString press(int typeOfTrain);
QString legs(int typeOfTrain);
void writeStat(const Training& training);
int trainingCounter(const Training& training);
void clear();
QString getName();
int getAge();
int getWeight();
int getHeight();
Sex getSex();
int getTypeOFTrain();
int water(int weight, Sex sex, int typeOfTrain);
double bmr(Sex sex,int age,int weight, int height, int typeOfTrain);
int b(int typeOfTrain);
int j(int typeOfTrain);
int u(int typeOfTrain);
QVector<int> getStat();
};
#endif // LOGIC_H
