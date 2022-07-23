#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linha.h"
#include "trem.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mutex1, mutex2, mutex3,mutex4;
void *thread_result;

void* train1(void*);
void* train2(void*);
void* train3(void*);
void* train4(void*);




pthread_t th1, th2, th3, th4;

linha l (50,50,200,200);
//Trem t (l.x-(l.x/2),l.y-(l.y/2),20,20,l.altura,l.largura,l.x-(l.x/2),l.x-(l.x/2));
Trem t (l.x-(20/2),l.y-(20/2),20,20, l.altura,l.largura,l.x-(20/2),l.y-(20/2));

linha l2 (275,50,200,200);
//Trem t (l.x-(l.x/2),l.y-(l.y/2),20,20,l.altura,l.largura,l.x-(l.x/2),l.x-(l.x/2));
Trem t2 (l2.x-(20/2),l2.y-(20/2),20,20, l2.altura,l2.largura,l2.x-(20/2),l2.y-(20/2));

linha l3 (50,275,200,200);
//Trem t (l.x-(l.x/2),l.y-(l.y/2),20,20,l.altura,l.largura,l.x-(l.x/2),l.x-(l.x/2));
Trem t3 (l3.x-(20/2),l3.y-(20/2),20,20, l3.altura,l3.largura,l3.x-(20/2),l3.y-(20/2));

linha l4 (275,275,200,200);
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
    time->setInterval(10);
    time->start();



    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_mutex_init(&mutex3, NULL);
    pthread_mutex_init(&mutex4, NULL);

    pthread_create(&th1, NULL, train1, NULL);
    pthread_create(&th2, NULL, train2, NULL);
    pthread_create(&th3, NULL, train3, NULL);
    pthread_create(&th4, NULL, train4, NULL);



}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QBrush brush;
    painter.setBrush(brush);


    brush.setColor(QColor(255,0,255));
    brush.setStyle(Qt::SolidPattern);


    painter.drawRect(l.x,l.y,l.altura,l.largura);
    brush.setColor(QColor(200,0,0));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(t.x,t.y,t.altura,t.altura);


    //criaçao trem2
    painter.drawRect(l2.x,l2.y,l2.altura,l2.largura);
    brush.setColor(QColor(0,255,0));
    painter.setBrush(brush);
    painter.drawRect(t2.x,t2.y,t2.altura,t2.altura);


    //criaçao trem3
    painter.drawRect(l3.x,l3.y,l3.altura,l3.largura);
    brush.setColor(QColor(0,0,255));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(t3.x,t3.y,t3.altura,t3.altura);

    //criaçao trem4
    painter.drawRect(l4.x,l4.y,l4.altura,l4.largura);
    brush.setColor(QColor(0,255,255));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(t4.x,t4.y,t4.altura,t4.altura);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// função para atualizar a tela
void MainWindow::movimentar()
{

    repaint();
}
// setando velocidades para os três
void MainWindow::velocidade1(int v1)
{
    if(v1 == 0 ){
       t.v = 1;
    }
    else
        t.v = v1;
}

void MainWindow::velocidade2(int v2)
{
    if(v2 == 0 ){
       t2.v = 1;
    }
    else
        t2.v = v2;
}

void MainWindow::velocidade3(int v3)
{
    if(v3 == 0 ){
       t3.v = 1;
    }
    else
        t3.v = v3;
}
void MainWindow::velocidade4(int v4)
{
    if(v4 == 0 ){
       t4.v = 1;
    }
    else
        t4.v = v4;
}
void* train1(void*){
   while(1){
       while(t.x<= t.xinicial + t.larguraLinha-t.largura/2 && t.y == t.yinicial){
           t.movimentar();
           QThread::msleep ( (1/t.v) * 250 );


       }
       pthread_mutex_lock(&mutex1);
          while(t.x>= t.xinicial + t.larguraLinha - t.largura/2 && t.y < t.yinicial +t.alturaLinha ){

              t.movimentar();
              QThread::msleep ( (1/t.v) * 250 );
            }

       pthread_mutex_unlock(&mutex1);

       pthread_mutex_lock(&mutex2);
       while(t.x >= t.xinicial && t.y > t.altura){

           t.movimentar();
           QThread::msleep ( (1/t.v) * 250 );

         }
       pthread_mutex_unlock(&mutex2);

       while(t.x < t.xinicial+t.largura/2 && t.y > t.yinicial){

           t.movimentar();
           QThread::msleep ( (1/t.v) * 250  );
         }
    }
}

void* train2(void*){
    while(1){

        while(t2.x<= t2.xinicial + t2.larguraLinha && t2.y == t2.yinicial){
            t2.movimentar();
            QThread::msleep ((1/t2.v) * 300  );
        }

           while(t2.x>= t2.xinicial + t2.larguraLinha){

               t2.movimentar();
               QThread::msleep ( (1/t2.v) * 300  );

             }


        pthread_mutex_lock(&mutex4);
        while(t2.x >= t2.xinicial+t2.largura/2 && t2.y > t2.altura){
            t2.movimentar();
            QThread::msleep ( (1/t2.v) * 300  );

          }
        pthread_mutex_unlock(&mutex4);
        pthread_mutex_lock(&mutex1);
        while(t2.x <= t2.xinicial+t2.largura/2 && t2.y > t2.yinicial){
            t2.movimentar();
            QThread::msleep ( (1/t2.v) * 300  );

          }
        pthread_mutex_unlock(&mutex1);

   }

}
void* train3(void*){
    while(1){
        pthread_mutex_lock(&mutex2);
        while(t3.x<= t3.xinicial + t3.larguraLinha && t3.y == t3.yinicial){
            t3.movimentar();
            QThread::msleep ( (1/t3.v) * 350 );
        }
        pthread_mutex_unlock(&mutex2);

          pthread_mutex_lock(&mutex3);
           while(t3.x>= t3.xinicial + t3.larguraLinha){

               t3.movimentar();
               QThread::msleep ( (1/t3.v) * 350 );

             }
            pthread_mutex_unlock(&mutex3);


        while(t3.x >= t3.xinicial+t3.largura/2 && t3.y > t3.altura){
            t3.movimentar();
            QThread::msleep ( (1/t3.v) * 350 );

          }

        while(t3.x < t3.xinicial+t3.largura/2 && t3.y > t3.yinicial){
            t3.movimentar();
            QThread::msleep ( (1/t3.v) * 350 );

          }


   }

}
void* train4(void*){
    while(1){

        pthread_mutex_lock(&mutex4);
        while(t4.x<= t4.xinicial + t4.larguraLinha && t4.y == t4.yinicial){
            t4.movimentar();
            QThread::msleep (  (1/t4.v) * 400 );
        }
        pthread_mutex_unlock(&mutex4);

           while(t4.x>= t4.xinicial + t4.larguraLinha){

               t4.movimentar();
               QThread::msleep (  (1/t4.v) * 400 );

             }



        while(t4.x >= t4.xinicial+t4.largura/2 && t4.y > t4.altura){
            t4.movimentar();
            QThread::msleep (  (1/t4.v) * 400 );

          }
        pthread_mutex_lock(&mutex3);
        while(t4.x < t4.xinicial+t4.largura/2 && t4.y > t4.yinicial){
            t4.movimentar();
            QThread::msleep (  (1/t4.v) * 400 );

          }
        pthread_mutex_unlock(&mutex3);

   }

}



