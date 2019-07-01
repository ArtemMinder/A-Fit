#ifndef HOMEFORM_H
#define HOMEFORM_H

#include <QDialog>
#include <QPieSeries>
#include <QChartView>
#include <QStackedBarSeries>
#include <QPieSlice>
#include <QChart>

#include <QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include "logic.h"

namespace Ui {
class HomeForm;
}

class HomeForm : public QDialog
{
    Q_OBJECT

public:
    explicit HomeForm(const Logic& in_logic, QWidget *parent = nullptr);
    ~HomeForm();

private slots:

    void on_home_clicked();

    void on_train_clicked();

    void on_graph_2_clicked();

    void on_reportButton_clicked();

    void on_warmUpInfo_clicked();

    void on_bicepsInfo_clicked();

    void on_chestInfo_clicked();

    void on_pressInfo_clicked();

    void on_legsInfo_clicked();

    void on_dtButton_clicked();

    void on_White_2_clicked();

    void on_resetButton_2_clicked();

private:
    Ui::HomeForm *ui;
    Logic logic;
    QtCharts::QPieSeries pieSeries;
    QtCharts::QStackedBarSeries barPlotSeries;
    QtCharts::QChart chart1;
    QtCharts::QChartView pieChartView;
    QtCharts::QChartView barChartView;
    QtCharts::QChart barChart;
    QtCharts::QBarCategoryAxis axisX;
    QtCharts::QValueAxis axisY;
};

#endif // HOMEFORM_H
