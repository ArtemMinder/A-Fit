#include "maindial.h"
#include <QApplication>
#include "logic.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logic logic;
    MainDial w(nullptr,logic);
    w.show();

    return a.exec();
}
