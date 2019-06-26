#ifndef HOMEFORM_H
#define HOMEFORM_H

#include <QDialog>
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

    void on_warmUpInfo_triggered(QAction *arg1);

    void on_warmUpInfo_clicked();

    void on_bicepsInfo_clicked();

    void on_chestInfo_clicked();

    void on_pressInfo_clicked();

    void on_legsInfo_clicked();

private:
    Ui::HomeForm *ui;
    Logic logic;
};

#endif // HOMEFORM_H
