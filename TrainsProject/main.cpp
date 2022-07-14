#include "mainwindow.h"
#include "trem.h"
#include <QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int i = 0;
    while(i<1000000){
       qDebug()<<1;
       i++;
       qDebug()<<i;
    }

    return a.exec();
}
