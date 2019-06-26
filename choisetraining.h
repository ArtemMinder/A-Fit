#ifndef CHOISETRAINING_H
#define CHOISETRAINING_H

#include <QDialog>

namespace Ui {
class ChoiseTraining;
}

class ChoiceTraining : public QDialog
{
    Q_OBJECT

public:
    explicit ChoiceTraining(QWidget *parent = nullptr);
    ~ChoiceTraining();

private:
    Ui::ChoiseTraining *ui;
};

#endif // CHOISETRAINING_H
