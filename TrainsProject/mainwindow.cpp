#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linha.h"
#include "trem.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QTimer>

linha l (50,50,200,200);
//Trem t (l.x-(l.x/2),l.y-(l.y/2),20,20,l.altura,l.largura,l.x-(l.x/2),l.x-(l.x/2));
Trem t (l.x-(20/2),l.y-(20/2),20,20, l.altura,l.largura,l.x-(20/2),l.y-(20/2));

linha l2 (260,50,200,200);
//Trem t (l.x-(l.x/2),l.y-(l.y/2),20,20,l.altura,l.largura,l.x-(l.x/2),l.x-(l.x/2));
Trem t2 (l2.x-(20/2),l2.y-(20/2),20,20, l2.altura,l2.largura,l2.x-(20/2),l2.y-(20/2));

linha l3 (50,260,200,200);
//Trem t (l.x-(l.x/2),l.y-(l.y/2),20,20,l.altura,l.largura,l.x-(l.x/2),l.x-(l.x/2));
Trem t3 (l3.x-(20/2),l3.y-(20/2),20,20, l3.altura,l3.largura,l3.x-(20/2),l3.y-(20/2));

linha l4 (260,260,200,200);
//Trem t (l.x-(l.x/2),l.y-(l.y/2),20,20,l.altura,l.largura,l.x-(l.x/2),l.x-(l.x/2));
Trem t4 (l4.x-(20/2),l4.y-(20/2),20,20, l4.altura,l4.largura,l4.x-(20/2),l4.y-(20/2));




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *time = new QTimer(this);
    connect(time
            ,SIGNAL(timeout()),
            this,
            SLOT(movimentar()));
    time->setInterval(30);
    time->start();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    //brush.setColor(QColor(r,g,b));
    //brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(l.x,l.y,l.altura,l.largura);
//    brush.setColor(QColor(200,0,0));
//    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(t.x,t.y,t.altura,t.altura);


    //criaçao trem2
    painter.drawRect(l2.x,l2.y,l2.altura,l2.largura);
    painter.drawRect(t2.x,t2.y,t2.altura,t2.altura);


//    //criaçao trem3
//    painter.drawRect(l3.x,l3.y,l3.altura,l3.largura);
//    painter.drawRect(t3.x,t3.y,t3.altura,t3.altura);

//    //criaçao trem4
//    painter.drawRect(l4.x,l4.y,l4.altura,l4.largura);
//    painter.drawRect(t4.x,t4.y,t4.altura,t4.altura);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::movimentar()
{

    t.movimentar();
    t2.setVelocidade(10);
    t2.movimentar();
    t3.setVelocidade(20);
    t3.movimentar();
    t4.setVelocidade(15);
    t4.movimentar();
    repaint();

//    qDebug() << t.x;
//    qDebug() << "largura " << t.x;
//    qDebug() << "altura " << t.y;
//    qDebug() << "largura  inicial " << t.xinicial;
//    qDebug() << "altura  inicial " << t.yinicial;
    //

}

