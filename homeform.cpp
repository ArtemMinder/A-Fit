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
#include <QStyleFactory>
QT_CHARTS_USE_NAMESPACE

HomeForm::HomeForm(const Logic& in_logic, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeForm),
    logic(in_logic),
    pieSeries(),
    barPlotSeries(),
    chart1(),
    pieChartView(),
    barChartView(),
    barChart(),
    axisX(),
    axisY()
{
    ui->setupUi(this);
    User user;
    ui->Name->setText(logic.getName());
    ui->nLabel->setNum(logic.getAge());
    ui->mbrInf->setNum(logic.bmr(logic.getSex(),logic.getAge(),logic.getWeight(),logic.getHeight(),logic.getTypeOFTrain()));
    ui->wtrInfo->setNum(logic.water(logic.getWeight(),logic.getSex(),logic.getTypeOFTrain()));
    ui->Name->setText(logic.getName());
    ui->nLabel->setNum(logic.getAge());
    if (logic.getSex()==Sex::female){
        QPixmap pix(":/images/woman.png");
        ui->userLabel->setPixmap(pix);
    }
    else {
        QPixmap pix(":/images/man.png");
        ui->userLabel->setPixmap(pix);
    }
    axisX.setParent(this->parent());
    barPlotSeries.setParent(this->parent());
    pieSeries.setParent(this->parent());
    chart1.setParent(this->parent());
    barChart.setParent(this->parent());
    chart1.addSeries(&pieSeries);
    pieSeries.setPieSize(0.9);
    pieSeries.setHoleSize(0.5);
    pieSeries.setHorizontalPosition(0.45);
    pieChartView.setChart(new QChart());
    ui->verticalLayout->addWidget(&pieChartView);
    barChartView.setChart(&barChart);
    ui->verticalLayout_2->addWidget(&barChartView);
}

HomeForm::~HomeForm()
{
    delete ui;
}

void HomeForm::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void HomeForm::on_train_clicked()
{
    User user;
    ui->stackedWidget->setCurrentIndex(1);
}

void HomeForm::on_graph_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    pieSeries.clear();
    pieSeries.append("Белки",logic.b(logic.getTypeOFTrain()));
    pieSeries.append("Жиры",logic.j(logic.getTypeOFTrain()));
    pieSeries.append("Углеводы", logic.u(logic.getTypeOFTrain()));

    chart1.setAnimationOptions(QChart::SeriesAnimations);
    chart1.legend();
    chart1.legend()->setAlignment(Qt::AlignRight);
    QPieSlice *slice1 = pieSeries.slices().at(0);

    slice1->setPen(QPen(Qt::darkRed, 1));
    slice1->setBrush(Qt::red);
    slice1->setLabel(QString("%1% Белки").arg(100*slice1->percentage(), 0, 'f', 1));
    QPieSlice *slice2 = pieSeries.slices().at(1);

    slice2->setPen(QPen(Qt::darkYellow, 1));
    slice2->setBrush(Qt::yellow);
    slice2->setLabel(QString("%1% Жиры").arg(100*slice2->percentage(), 0, 'f', 1));
    QPieSlice *slice3 = pieSeries.slices().at(2);

    slice3->setPen(QPen(Qt::darkBlue, 1));
    slice3->setBrush(Qt::blue);
    slice3->setLabel(QString("%1% Углеводы").arg(100*slice3->percentage(), 0, 'f', 1));
    pieChartView.setChart(&chart1);
    pieChartView.setRenderHint(QPainter::Antialiasing);
    pieChartView.repaint();
    pieChartView.setRenderHint(QPainter::Antialiasing);
    pieChartView.repaint();

    barPlotSeries.clear();
    QBarSet *bar1 = new QBarSet("Разминка");
    QBarSet *bar2 = new QBarSet("Бицепс");
    QBarSet *bar3 = new QBarSet("Грудь");
    QBarSet *bar4 = new QBarSet("Пресс");
    QBarSet *bar5 = new QBarSet("Ноги");
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
    *bar1 <<  training.warmUp*20;
    *bar2  << training.biceps*20;
    *bar3  << training.chest*20;
    *bar4  << training.press*20;
    *bar5  << training.legs*20;
    *bar1 << 20;
    *bar2 << 20;
    *bar3 << 20;
    *bar4 << 20;
    *bar5 << 20;
    /**bar1 << (logic.vector().value(1))*20;
     *bar2 << logic.vector().value(2);
     *bar3 << logic.vector().value(3);
     *bar4 << logic.vector().value(4);
     *bar5 << logic.vector().value(5);*/
    // QStackedBarSeries *series4 = new QStackedBarSeries();
    barPlotSeries.append(bar1);
    barPlotSeries.append(bar2);
    barPlotSeries.append(bar3);
    barPlotSeries.append(bar4);
    barPlotSeries.append(bar5);
    //  QChart *chart4 = new QChart();
    barChart.addSeries(&barPlotSeries);
    //  chart4->setTitle("Simple stackedbarchart example");
    barChart.setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories << "1" << "2" << "3" << "4" << "5" << "6"<<"7";
    // QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX.append(categories);
    barChart.addAxis(&axisX, Qt::AlignBottom);
    barPlotSeries.attachAxis(&axisX);
    //QValueAxis *axisY = new QValueAxis();
    barChart.addAxis(&axisY, Qt::AlignLeft);
    barPlotSeries.attachAxis(&axisY);
    barChart.legend()->setVisible(true);
    barChart.legend()->setAlignment(Qt::AlignRight);
    //  QChartView *chartView2 = new QChartView();
    barChartView.setChart(&barChart);
    barChartView.setRenderHint(QPainter::Antialiasing);
    barChartView.repaint();

//    //slice3->setExploded();
//    //slice3->setLabelVisible();
//    slice3->setPen(QPen(Qt::darkBlue, 1));
//    slice3->setBrush(Qt::blue);
//    slice3->setLabel(QString("%1% Углеводы").arg(100*slice3->percentage(), 0, 'f', 1));

//    pieChartView.setChart(&chart1);
//    pieChartView.setRenderHint(QPainter::Antialiasing);
//    pieChartView.repaint();

//    //QChartView *chartView = new QChartView(chart);
//    pieChartView.setRenderHint(QPainter::Antialiasing);
//    //pieChartView.repaint();
//   // ui->verticalLayout->addWidget(&pieChartView);



//                 QBarSet *set0 = new QBarSet("Разминка");
//                 QBarSet *set1 = new QBarSet("Бицепс");
//                 QBarSet *set2 = new QBarSet("Грудь");
//                 QBarSet *set3 = new QBarSet("Пресс");
//                 QBarSet *set4 = new QBarSet("Ноги");
//                 Training training;
//                 *set0 << training.warmUp*20;
//                 *set1 << training.biceps*20;
//                 *set2 << training.chest*20;
//                 *set3 << training.press*20;
//                 *set4 << training.legs*20;
//                 *set0 << 20;
//                 *set1 << 20;
//                 *set2 << 20;
//                 *set3 << 20;
//                 *set4 << 20;
//                 QStackedBarSeries *series4 = new QStackedBarSeries();
//                 series4->append(set0);
//                 series4->append(set1);
//                 series4->append(set2);
//                 series4->append(set3);
//                 series4->append(set4);
//                 QChart *chart4 = new QChart();
//                 chart4->addSeries(series4);
//                 //  chart4->setTitle("Simple stackedbarchart example");
//                 chart4->setAnimationOptions(QChart::SeriesAnimations);
//                 QStringList categories;
//                 categories << "1" << "2" << "3" << "4" << "5" << "6"<<"7";
//                 QBarCategoryAxis *axisX = new QBarCategoryAxis();
//                 axisX->append(categories);
//                 chart4->addAxis(axisX, Qt::AlignBottom);
//                 series4->attachAxis(axisX);
//                 QValueAxis *axisY = new QValueAxis();
//                 chart4->addAxis(axisY, Qt::AlignLeft);
//                 series4->attachAxis(axisY);
//                 chart4->legend()->setVisible(true);
//                 chart4->legend()->setAlignment(Qt::AlignRight);
//                 QChartView *chartView2 = new QChartView();
//                 chartView2->setChart(chart4);
//                 chartView2->setRenderHint(QPainter::Antialiasing);
//                 ui->verticalLayout_2->replaceWidget(&barChartView,chartView2);
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
    logic.writeStat(training);

}

void HomeForm::on_warmUpInfo_clicked()
{
    QMessageBox::information(this,"Разминка",logic.warmUP(logic.getTypeOFTrain()));
}
void HomeForm::on_bicepsInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на бицепс",logic.biceps(logic.getTypeOFTrain()));
}
void HomeForm::on_chestInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на грудные мышцы",logic.chest(logic.getTypeOFTrain()));
}
void HomeForm::on_pressInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на мышцы пресса",logic.press(logic.getTypeOFTrain()));
}
void HomeForm::on_legsInfo_clicked()
{
    QMessageBox::information(this,"Тренировка на ноги",logic.legs(logic.getTypeOFTrain()));
}

void HomeForm::on_dtButton_clicked()
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

void HomeForm::on_White_2_clicked()
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
