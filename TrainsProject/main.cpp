#include "mainwindow.h"
#include "trem.h"
#include <QApplication>
#include <qdebug.h>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
