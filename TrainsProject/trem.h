#ifndef TREM_H
#define TREM_H


#include "qobjectdefs.h"
class Trem
{
public:
    int x;
    int y;
    int altura, largura;
    int alturaLinha, larguraLinha;
    int velocidade = 3;
    int xinicial = 0;
    int yinicial = 0;
    float v = 1;

    Trem(int x, int y,int altura,int largura, int alturaLinha, int larguraLinha, int xincial, int yincial);



    int getVelocidade();

    void setVelocidade(int velocidade);


    void movimentar();

signals:

public slots:
    void setv(int v);


};

#endif // TREM_H
