#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void delay();
    ~MainWindow();

public slots:
    void movimentar();
    void velocidade1(int v1);
    void velocidade2(int v2);
    void velocidade3(int v3);
    void velocidade4(int v4);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
