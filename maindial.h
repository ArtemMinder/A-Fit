#ifndef MAINDIAL_H
#define MAINDIAL_H

#include <QMainWindow>
#include "user.h"
#include "logic.h"
#include "homeform.h"




namespace Ui {
class MainDial;
}

class MainDial : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDial(QWidget *parent,Logic logic);
    ~MainDial();

private slots:
    void on_confirmButton_2_clicked();

    void on_White_clicked();

    void on_dtButton_clicked();

private:
    Ui::MainDial *ui;
    Logic logic;
    HomeForm *home;
};

#endif // MAINDIAL_H
