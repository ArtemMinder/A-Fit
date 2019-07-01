#include "logic.h"
#include "QFile"
#include "user.h"
#include "QDebug"
#include <QTextCodec>
#include <QVector>


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
      else file.write("Пол не выбран");
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
void Logic::clear(){
    QFile file("TrainingStatistic.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    file.close();
    QFile file1("UserData.txt");
    if (file1.open(QIODevice::WriteOnly | QIODevice::Truncate))
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
QString Logic::warmUP(int typeOfTrain){
    if(typeOfTrain == 1) return  "Кардио:\nПосвятите первые 5-7 минут разминки легкой пробежке на беговой дорожке, велотренажеру или любому другому кардио. При этом важно сохранять умеренный темп и поддерживать пульс не выше 120-130 ударов в минуту. Ваша задача — немного вспотеть, но не вымотаться. Наклоняйте голову влево, потом вправо. Делайте упражнение в течение 15—20 секунд. Можете в это же время разминать и кисти рук — крутите их сначала по часовой стрелке, затем против. Стойте прямо, ноги на ширине плеч. Поднимите руки перед собой и выпрямите, сцепите ладони в замок. Бёдра остаются неподвижными, округляется только спина и поясница. Тянитесь вперёд, растягивая мышцы спины, в течение 10—15 секунд. Поднимите левую ногу перед собой, обхватите колено обеими руками. Тяните ногу к туловищу в течение 15—20 секунд. Повторите с другой ногой.";
    if(typeOfTrain == 2) return  "Кардио:\nПосвятите первые 5-7 минут разминки легкой пробежке на беговой дорожке, велотренажеру или любому другому кардио. При этом важно сохранять умеренный темп и поддерживать пульс не выше 120-130 ударов в минуту. Ваша задача — немного вспотеть, но не вымотаться. Наклоняйте голову влево, потом вправо. Делайте упражнение в течение 15—20 секунд. Можете в это же время разминать и кисти рук — крутите их сначала по часовой стрелке, затем против. Стойте прямо, ноги на ширине плеч. Поднимите руки перед собой и выпрямите, сцепите ладони в замок. Бёдра остаются неподвижными, округляется только спина и поясница. Тянитесь вперёд, растягивая мышцы спины, в течение 10—15 секунд. Поднимите левую ногу перед собой, обхватите колено обеими руками. Тяните ногу к туловищу в течение 15—20 секунд. Повторите с другой ногой.";
    if(typeOfTrain == 3) return  "Кардио:\nПосвятите первые 5-7 минут разминки легкой пробежке на беговой дорожке, велотренажеру или любому другому кардио. При этом важно сохранять умеренный темп и поддерживать пульс не выше 120-130 ударов в минуту. Ваша задача — немного вспотеть, но не вымотаться. Наклоняйте голову влево, потом вправо. Делайте упражнение в течение 15—20 секунд. Можете в это же время разминать и кисти рук — крутите их сначала по часовой стрелке, затем против. Стойте прямо, ноги на ширине плеч. Поднимите руки перед собой и выпрямите, сцепите ладони в замок. Бёдра остаются неподвижными, округляется только спина и поясница. Тянитесь вперёд, растягивая мышцы спины, в течение 10—15 секунд. Поднимите левую ногу перед собой, обхватите колено обеими руками. Тяните ногу к туловищу в течение 15—20 секунд. Повторите с другой ногой.";
    else return QString();
}
QString Logic::biceps(int typeOfTrain){
    if(typeOfTrain == 1) return  "Подъем штанги:\nПодъем штанги на бицепс стоя — это базовое упражнение на бицепс. Оно считается одним из самых эффективных для наращивания объёма и силы бицепсов. За гриф штанги нужно браться на ширине плеч, хватом снизу. Сокращением бицепсов снаряд поднимается. Нужно следить за тем, чтобы локти не выносились вперед. Обычно, это происходит тогда, когда атлет пытается поднять штангу повыше. Этого делать не стоит, так как нагрузка будет переходить с бицепса на дельту.\nРабота со штангой на скамье Скотта:\nШтангу следует держать обратным средним хватом. Плечи должны лежать на опоре. В таком положении нагрузка приходится только на бицепс. Как вариант, можно использовать скамью Скотта, чтобы выполнять упражнения на бицепс с гантелями. Количество повторений: 8-12. Количество подходов: 3.";
    if(typeOfTrain == 2) return  "Сгибание рук с гантелям:\nПодойдут самые обычные гантели. Эффективнее всего бицепс прокачивает сгибание рук сидя на стуле: Сесть на стул. Изять гантели. Сгибать и разгибать руки в локтевых суставах. На выдохе рука должна сгибаться, а на вдохе – разгибаться. Начинать можно с 8-12 повторений. Если чувствуете, что повторения даются без труда, следует увеличить вес гантелей. Количество подходов: 3.\nМолотковый подъем гантелей:\nДанное упражнение прокачивает боковую часть бицепса, формируя его. Bстать прямо. Pуки с гантелями опущены вниз по бокам туловища. Кисти развернуты пальцами к бедру (нейтральный хват). Поочередно поднимать гантели к плечу. В каждом крайнем положении руку следует задерживать на 1-2 секунды. Количество повторений: 8-12. Количество подходов: 3. ";
    if(typeOfTrain == 3) return  "Сгибание рук, сидя на наклонной скамье:\nДля выполнения этого упражнения, необходимо сесть на наклонную скамью и взять в руки гантели. Ноги должны быть плотно прижаты к полу, а спина – к спинке скамьи. Руки надо поочередно сгибать в локтевых суставах, поднимая гантели. В верхнем положении нужно максимально разворачивать кисти к себе. Локти нельзя подавать вперед. Подходов: 3 Повторений 20+";
    else return QString();
}
QString Logic::chest(int typeOfTrain){
    if(typeOfTrain == 1) return "Отжимания на табуретках:\nБолее эффективный способ, чтобы отжиманиями накачать грудные мышцы, заключается в следующем. Нужно поставить 2 табуретки примерно на ширину плеч. Принять исходное положение, как при отжиманиях от пола, только руки расположить на табуретках, а ноги на другом возвышении, например, диване или кресле. Ладони при этом расставить немного шире плеч. Подходов: 3 Повтореий: 15+ ";
    if(typeOfTrain == 2) return "Узкие отжимания:\nОтжимания от пола узким хватом можно применять для развития силы и проработки внутренней части груди. Исходное положение в данном случае, как при обычных отжиманиях, но руки нужно ставить таким образом, чтобы пальцы одной руки чуть касались пальцев другой. При выполнении, опускаться необходимо до касания грудью рук, а перед движением вверх выдерживать секундную паузу. Подходов: 3";
    if(typeOfTrain == 3) return  "Разведение рук с гантелями:\nЭто упражнение хорошо прорабатывает грудные мышцы. Лягте на пол на спину, возьмите в руки гантели и поднимите их перед собой. Разведите руки, слегка сгибая их в локтях, настолько широко, чтобы коснуться локтями пола. Не сгибайте локти сильно, чтобы сведение рук не превратилось в жим гантелей. На выдохе сведите руки перед собой и повторите упражнение. Подходов: 3 Повторенй: 20+";
    else return QString();
}
QString Logic::press(int typeOfTrain){
    if(typeOfTrain == 1) return  "Скручивание на тренажёре:\nТехника выполнения следующая. Сесть на тренажёр, ноги зафиксировать, взяться за рукоятки. Выполнить наклон к коленям, скручивая корпус. Вернуться в исходное положение. На одних тренажёрах сопротивление производится подъёмом веса, на других – давлением грудью на упор. Данное упражнение эффективно для верхнего пресса, косых мышц и передней зубчатой мышцы живота. Подходов: 3 Повторений: 15+\nСкручивание на блоке:\nНужно встать спиной к верхнему блоку, опуститься на колени, после чего обхватить рукоятку троса. Удерживать рукоятку можно за головой, а можно и перед грудью. При выполнении упражнения для верхнего пресса помните, что нагрузка увеличивается пропорционально высоте расположения рук. Суть сводится к наклонам вперед с одновременным скручиванием корпуса. Подходов: 3 Повторений: 15+";
    if(typeOfTrain == 2) return  "Подъём корпуса на наклонной скамье:\nНужно сесть на верхний край скамьи, зафиксировать ноги, отклониться назад. Исходное положение – корпус практически параллелен полу. Поднять корпус перпендикулярно полу. Вернуться в исходное положение. При этом руки можно свести в «замок» за головой, скрестить на груди или сложить за спиной. В верхней точке упражнения живот почти касается бёдер, в нижней точке – корпус параллелен полу. Подходов: 3 Повторений: 20+";
    if(typeOfTrain == 3) return  "Скручивание:\nЛечь на спину, согнув ноги в коленях. Ноги могут стоять на полу, лежать на скамье под прямым углом или активно участвовать в упражнении. Руки сложены за головой. Необходимо медленно поднимать корпус и поворачивать его – сначала влево, затем вправо, стремясь к тому, чтобы локоть задевал противоположное колено. Поясница полностью прижата к полу, в упражнении должна быть задействована только верхняя часть спины. Подъём делается на выдохе через рот, опускание – на вдохе через нос. Для начала достаточно 8-10 раз по 3 подхода. Постепенно увеличивайте количество повторений до 50.";
    else return QString();
}
QString Logic::legs(int typeOfTrain){
    if(typeOfTrain == 1) return  "Разгибание ног на тренажёре:\nСпинку нужно установить так, чтобы ваше бедро полностью помещалось на сиденье. То есть, чтобы колени идеально ложились на край сиденья, а крестец был прижат к спинке. Угол в коленном суставе при этом не должен быть меньше 90 градусов. Выбирайте вес так, чтобы с ним вы смогли сделать 3–4 подхода по 15–20 раз. Большое отягощение в этом упражнении не используется. Подходов: 3 Повторений: 15+";
    if(typeOfTrain == 2) return  "Бег:\nДля начала будет достаточно 2-4 тренировок в неделю по 10-20 минут. Со временем вы наберетесь сил и сможете бегать чаще и больше. Помните, что главное в беге - не пройденный километраж, а постоянство и регулярность. Не перегружайте себя и не бегайте на износ, а лучше задайте себе собственный темп и нагрузку.";
    if(typeOfTrain == 3) return  "Присед:\nНоги поставьте на ширине плеч или чуть шире.На вдохе начинайте приседать, как будто пытаетесь сесть на невидимый стул. Приседайте до тех пор, пока бедра не станут параллельны полу или чуть ниже.На выдохе вернитесь в исходное положение. Желательно выполнять 4–5 подходов по 10–12 раз.";
    else return QString();
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
void Logic::writeStat(const Training& training){
    QFile file ("TrainingStatistic.txt");
    QStringList strList;
    /*Считываем исходный файл в контейнер*/
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    { while(!file.atEnd())
        {
            strList << file.readLine();


        }
        file.close();

    }
    QFile inputFile("TrainingStatistic.txt");
    if (inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        in.setCodec(QTextCodec::codecForName("UTF-8"));
        QString str = in.readAll();
        QTextStream s(&str);
        QString count;
        for (size_t i = 0; i < 35; i++)
            count= s.readLine();
        if(count!=QString()){QFile file("TrainingStatistic.txt");
            if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                file.close();}
        inputFile.close();
        if (file.open(QIODevice::Append))
        {
        QString newWarmUp = QString::number(training.warmUp);
        file.write(newWarmUp.toUtf8());
        file.write("\n");
        QString newBiceps = QString::number(training.biceps);
        file.write(newBiceps.toUtf8());
        file.write("\n");
        QString newChest = QString::number(training.chest);
        file.write(newChest.toUtf8());
        file.write("\n");
        QString newPress = QString::number(training.press);
        file.write(newPress.toUtf8());
        file.write("\n");
        QString newLegs = QString::number(training.legs);
        file.write(newLegs.toUtf8());
        file.write("\n");
        file.close();
         }
        file.close();
}};
QVector<int> Logic::getStat(){
    QFile file("TrainingStatistic.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() <<  "Cannot open a file";
    }

    QVector<int> vector(100);
    int i = 0;
    QTextStream in(&file);

    while (!in.atEnd())
    {
        vector[i] = in.readLine().toInt();
        i++;
    }
    return vector;
}
