#include "homeform.h"
#include "ui_homeform.h"
#include "logic.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPixmap>
#include "training.h"
#include <QBarCategoryAxis>
#include <QBarLegendMarker>
#include <QBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QStackedBarSeries>
#include <QValueAxis>
#include <QChart>
QT_CHARTS_USE_NAMESPACE

HomeForm::HomeForm(const Logic& in_logic, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeForm),
    logic(in_logic)

{

    ui->setupUi(this);
    ui->Name->setText(logic.getName());
    ui->nLabel->setNum(logic.getAge());
    ui->mbrInf->setNum(logic.bmr(logic.getSex(),logic.getAge(),logic.getWeight(),logic.getHeight(),logic.getTypeOFTrain()));
    ui->wtrInfo->setNum(logic.water(logic.getWeight(),logic.getSex(),logic.getTypeOFTrain()));
    QPieSeries *series = new QPieSeries();
    series ->setPieSize(0.9);
    series->setHoleSize(0.5);
    series->setHorizontalPosition(0.45);
        series->append("Белки",logic.b(logic.getTypeOFTrain()));
        series->append("Жиры",logic.j(logic.getTypeOFTrain()));
        series->append("Углеводы", logic.u(logic.getTypeOFTrain()));
        QChart *chart = new QChart();
        chart->addSeries(series);
        //chart->setTitle("Соотношение БЖУ");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->legend()->setX(-20);
        //chart->legend()->;
        chart->legend()->setAlignment(Qt::AlignRight);
        QPieSlice *slice1 = series->slices().at(0);
               //slice1->setExploded();
               //slice1->setLabelVisible();
               slice1->setPen(QPen(Qt::darkRed, 1));
               slice1->setBrush(Qt::red);
               slice1->setLabel(QString("%1% Белки").arg(100*slice1->percentage(), 0, 'f', 1));
        QPieSlice *slice2 = series->slices().at(1);
               //slice2->setExploded();
              // slice2->setLabelVisible();
               slice2->setPen(QPen(Qt::darkYellow, 1));
               slice2->setBrush(Qt::yellow);
               slice2->setLabel(QString("%1% Жиры").arg(100*slice2->percentage(), 0, 'f', 1));
        QPieSlice *slice3 = series->slices().at(2);
               //slice3->setExploded();
               //slice3->setLabelVisible();
               slice3->setPen(QPen(Qt::darkBlue, 1));
               slice3->setBrush(Qt::blue);
               slice3->setLabel(QString("%1% Углеводы").arg(100*slice3->percentage(), 0, 'f', 1));
               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               ui->verticalLayout->addWidget(chartView);


               QBarSet *set0 = new QBarSet("Разминка");
                   QBarSet *set1 = new QBarSet("Бицепс");
                   QBarSet *set2 = new QBarSet("Грудь");
                   QBarSet *set3 = new QBarSet("Пресс");
                   QBarSet *set4 = new QBarSet("Ноги");
                   Training training;
                   *set0 << training.warmUp;
                   *set1 << training.biceps;
                   *set2 << training.chest;
                   *set3 << training.press;
                   *set4 << training.legs;
                  /* *set0 << 20;
                   *set1 << 20;
                   *set2 << 20;
                   *set3 << 20;
                   *set4 << 20;*/
                   QStackedBarSeries *series4 = new QStackedBarSeries();
                      series4->append(set0);
                      series4->append(set1);
                      series4->append(set2);
                      series4->append(set3);
                      series4->append(set4);
                      QChart *chart4 = new QChart();
                         chart4->addSeries(series4);
                       //  chart4->setTitle("Simple stackedbarchart example");
                         chart4->setAnimationOptions(QChart::SeriesAnimations);
                         QStringList categories;
                             categories << "1" << "2" << "3" << "4" << "5" << "6";
                             QBarCategoryAxis *axisX = new QBarCategoryAxis();
                             axisX->append(categories);
                             chart4->addAxis(axisX, Qt::AlignBottom);
                             series4->attachAxis(axisX);
                             QValueAxis *axisY = new QValueAxis();
                             chart4->addAxis(axisY, Qt::AlignLeft);
                             series4->attachAxis(axisY);
                             chart4->legend()->setVisible(true);
                                 chart4->legend()->setAlignment(Qt::AlignRight);
                                 QChartView *chartView2 = new QChartView();
                                 chartView2->setChart(chart4);
                                 chartView2->setRenderHint(QPainter::Antialiasing);

                                     ui->verticalLayout_2->addWidget(chartView2);
                                     //ui->verticalLayout_2->itemAt(0)->widget();



}

HomeForm::~HomeForm()
{
    delete ui;

}


void HomeForm::on_home_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
ui->Name->setText(logic.getName());
ui->nLabel->setNum(logic.getAge());
User user;
if (logic.getSex()==Sex::female){
    QPixmap pix(":/images/woman.png");
    ui->userLabel->setPixmap(pix);
}
else {
    QPixmap pix(":/images/man.png");
    ui->userLabel->setPixmap(pix);
}

}

void HomeForm::on_train_clicked()
{
   User user;
   ui->stackedWidget->setCurrentIndex(1);


}

void HomeForm::on_graph_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);


}

void HomeForm::on_reportButton_clicked()
{
    Training training;
    if(ui->warmUpCB->isChecked()){
        training.warmUp=true;
    }
    if(ui->bicepsCB->isChecked()){
        training.biceps=true;
    }
    if(ui->chestCB->isChecked()){
        training.chest=true;
    }
    if(ui->pressCB->isChecked()){
        training.press=true;
    }
    if(ui->legsCB->isChecked()){
        training.legs=true;
    }
    ui->label_45->setNum(logic.trainingCounter(training));

}



void HomeForm::on_warmUpInfo_clicked()
{
    QMessageBox::information(this,"Разминка"," ");
}

void HomeForm::on_bicepsInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на бицепс"," ");
}

void HomeForm::on_chestInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на грудные мышци"," ");
}

void HomeForm::on_pressInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на мышци пресса"," ");
}

void HomeForm::on_legsInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на ноги"," ");
}
