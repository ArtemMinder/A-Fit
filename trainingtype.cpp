#include "trainingtype.h"
#include "ui_trainingtype.h"
#include "logic.h"

TrainingType::TrainingType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainingType)

{
    ui->setupUi(this);
}

TrainingType::~TrainingType()
{
    delete ui;
}
