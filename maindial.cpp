#include "maindial.h"
#include "ui_maindial.h"
#include "logic.h"
#include "user.h"
#include <QStyleFactory>
#include "homeform.h"


MainDial::MainDial(QWidget *parent, Logic newLogic) :
    QMainWindow(parent),
    ui(new Ui::MainDial),
    logic(newLogic)

{
    ui->setupUi(this);
    //if(logic.getName()!=QString()){home->open();}

    QObject::connect(ui->ageSlider_2, SIGNAL(valueChanged(int)),ui->ageNumber_2,SLOT(display(int)));
    QObject::connect(ui->massSlider_2, SIGNAL(valueChanged(int)),ui->massNumber_2,SLOT(display(int)));
    QObject::connect(ui->heightSlider_2, SIGNAL(valueChanged(int)),ui->heightNumber_2,SLOT(display(int)));
}


MainDial::~MainDial()
{
    delete ui;

}

void MainDial::on_confirmButton_2_clicked()
{
    User user;
    user.name=ui->nameTEdit_2->toPlainText();
    user.age=ui->ageNumber_2->intValue();
    user.weight=ui->massNumber_2->intValue();
    user.height=ui->heightNumber_2->intValue();
    if(ui->TR1->isChecked()){
        user.typeOfTraining=1;
    }
    if(ui->TR2->isChecked()){
        user.typeOfTraining=2;
    }
    if(ui->TR3->isChecked()){
        user.typeOfTraining=3;
    }
    if(ui->fRB_2->isChecked()){
        user.sex=(Sex::female);
    }
    else user.sex=(Sex::male);
    logic.saveUser(user);
    home= new HomeForm(logic,parentWidget());
    if(logic.getName()==QString()||logic.getTypeOFTrain()==0||logic.getSex()==Sex::unset){
        QMessageBox::warning(this,"Ключевые поля не заполнены","Пожалуйста, введите недостающие данные в форму");
    }
    else{  home->open();
        this->close();
    }
}

void MainDial::on_White_clicked()
{
    QApplication::setStyle(QStyleFactory::create("White"));
    QPalette p;
    p = qApp->palette();
    p.setColor(QPalette::Window, Qt::white);
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    qApp->setPalette(p);
}

void MainDial::on_dtButton_clicked()
{
    QApplication::setStyle(QStyleFactory::create("Dark"));
    QPalette p;
    p = qApp->palette();
    p.setColor(QPalette::Window, Qt::darkGray);
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    qApp->setPalette(p);
}
