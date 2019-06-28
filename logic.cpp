#include "logic.h"
#include "QFile"
#include "user.h"
#include "QDebug"
#include <QTextCodec>


Logic::Logic()
{

}

void Logic::saveUser(const User& user){
 QFile file ("UserData.txt");
 QStringList strList;
 /*Считываем исходный файл в контейнер*/
 if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
 { while(!file.atEnd())
     {
     strList << file.readLine();
     }
     file.close();
 }
 if (file.open(QIODevice::WriteOnly))
 {
     //file.write("Имя: ");
     file.write(user.name.toUtf8());
     file.write("\n");
     //file.write("Возраст: ");
     QString qAge= QString::number(user.age);
     file.write(qAge.toUtf8());
     file.write("\n");
    // file.write("Bec: ");
     QString qWeight = QString::number(user.weight);
     file.write(qWeight.toUtf8());
     file.write("\n");
     //file.write("Рост: ");
     QString qHeight = QString::number(user.height);
      file.write(qHeight.toUtf8());
      file.write("\n");
    //  file.write("Тип тренировки: ");
      QString tType = QString::number(user.typeOfTraining);
      file.write(tType.toUtf8());
      file.write("\n");
    //  file.write("Пол: ");
      if(user.sex==Sex::male){
          file.write("Мужской");
      }
     else if(user.sex==Sex::female){
          file.write("Женский");
      }
      else qDebug() << "Пол не выбран";
     file.close();
}}
QString Logic::getName(){
    QFile inputFile("UserData.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
     QTextStream in(&inputFile);
     in.setCodec(QTextCodec::codecForName("UTF-8"));
     QString str = in.readAll();
      QTextStream s(&str);
      QString name;
      name= s.readLine();
      inputFile.close();
      return name ;
    }
    return QString();
}
int Logic::getAge(){
    QFile inputFile("UserData.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       in.setCodec(QTextCodec::codecForName("UTF-8"));
       QString str = in.readAll();
       QTextStream s(&str);
       QString age;
       for (size_t i = 0; i < 2; i++)
       age= s.readLine();
       int a=age.toInt();
       inputFile.close();
       return a;
    }
    return 0;
}
int Logic::getWeight(){
    QFile inputFile("UserData.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       in.setCodec(QTextCodec::codecForName("UTF-8"));
       QString str = in.readAll();
       QTextStream s(&str);
       QString weight;
       for (size_t i = 0; i < 3; i++)
       weight= s.readLine();
       int b=weight.toInt();
       inputFile.close();
       return b;
    }
     return 0;
}
int Logic::getHeight(){
    QFile inputFile("UserData.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       in.setCodec(QTextCodec::codecForName("UTF-8"));
       QString str = in.readAll();
       QTextStream s(&str);
       QString height;
       for (size_t i = 0; i < 4; i++)
       height= s.readLine();
       int c=height.toInt();
       inputFile.close();
        return c;
    }
     return 0;
}
Sex Logic::getSex(){
    QFile inputFile("UserData.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
    QTextStream in(&inputFile);
    in.setCodec(QTextCodec::codecForName("UTF-8"));
    QString str = in.readAll();
    QTextStream s(&str);
    QString sex;
    for (size_t i = 0; i < 6; i++)
     sex= s.readLine();
     inputFile.close();
     if(sex=="Мужской"){
      return Sex::male;
     }
     if(sex=="Женский"){
      return Sex::female;
     }
    }
    return Sex::unset;

}
int Logic::getTypeOFTrain(){
    QFile inputFile("UserData.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       in.setCodec(QTextCodec::codecForName("UTF-8"));
       QString str = in.readAll();
       QTextStream s(&str);
       QString tType;
       for (size_t i = 0; i < 5; i++)
       tType= s.readLine();
       int t=tType.toInt();
       inputFile.close();
        return t;
    }
     return 0;
}
int Logic::water(int weight, Sex sex, int typeOfTrain){
    int water;
    if(sex==Sex::male){water = weight*32;}
    else {water = weight*28;}
    if(typeOfTrain == 1) water += 600;
    if(typeOfTrain == 2) water += 300;
    if(typeOfTrain == 3) water += 1200;
    return water;
}
double Logic::bmr(Sex sex,int age,int weight, int height, int typeOfTrain){
    double bmr;

    if(sex==Sex::male){
    bmr = 88.362 + (13.397 * weight) + (4.799 * height) -  (5.677 * age);}
    else bmr=774.593 + (9.247 * weight) + (3.089 * height) - (4.33 * age);
    if(typeOfTrain == 1) bmr *= 1.55;
    if(typeOfTrain == 2) bmr *= 1.357;
     if(typeOfTrain == 3) bmr *= 1.725;

 return bmr;

}
void clear(){
    QFile file("UserData.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    file.close();
}
int Logic::b(int typeOfTrain){
    if(typeOfTrain == 1){
        return 30;
    }
    if(typeOfTrain == 2){
        return 30;
    }
    if(typeOfTrain == 3){
        return 40;
    }
    return 0;
}
int Logic::j(int typeOfTrain){
    if(typeOfTrain == 1){
        return 20;
    }
    if(typeOfTrain == 2){
        return 30;
    }
    if(typeOfTrain == 3){
        return 30;
    }
    return 0;
}
int Logic::u(int typeOfTrain){
    if(typeOfTrain == 1){
        return 50;
    }
    if(typeOfTrain == 2){
        return 40;
    }
    if(typeOfTrain == 3){
        return 30;
    }
    return 0;
}
QString Logic::warmUP(int typeOfTraining){
    if(typeOfTraining == 1) return  "1111 1111111111111";
    if(typeOfTraining == 2) return  "";
     if(typeOfTraining == 3) return  "";
     return QString();
}
QString Logic::biceps(int typeOfTraining){
    if(typeOfTraining == 1) return  "";
    if(typeOfTraining == 2) return  "";
     if(typeOfTraining == 3) return  "";
     return QString();
}
QString Logic::chest(int typeOfTraining){
    if(typeOfTraining == 1) return  "";
    if(typeOfTraining == 2) return  "";
     if(typeOfTraining == 3) return  "";
     return QString();
}
QString Logic::press(int typeOfTraining){
    if(typeOfTraining == 1) return  "";
    if(typeOfTraining == 2) return  "";
     if(typeOfTraining == 3) return  "";
     return QString();
}
QString Logic::legs(int typeOfTraining){
    if(typeOfTraining == 1) return  "";
    if(typeOfTraining == 2) return  "";
     if(typeOfTraining == 3) return  "";
     return QString();
}
int Logic::trainingCounter(const Training& training){
    int counter = 0;
    if(training.warmUp==true) counter += 1;
     if(training.biceps==true) counter += 1;
      if(training.chest==true) counter += 1;
       if(training.press==true) counter += 1;
        if(training.legs==true) counter += 1;
        counter *= 20;
        return counter;
}
