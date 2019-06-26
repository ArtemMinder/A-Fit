#include "choisetraining.h"
#include "ui_choisetraining.h"

ChoiceTraining::ChoiceTraining(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoiseTraining)
{
    ui->setupUi(this);
}

ChoiceTraining::~ChoiceTraining()
{
    delete ui;
}
