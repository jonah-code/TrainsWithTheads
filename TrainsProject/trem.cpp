#include "trem.h"
#include <QDebug>
Trem::Trem(int x, int y,int altura,int largura, int alturaLinha, int larguraLinha, int xincial, int yincial)
{
    this->x = x;
    this->y = y;
    this->altura =altura;
    this->largura = largura;
    this->alturaLinha =alturaLinha;
    this->larguraLinha = larguraLinha;
    this->xinicial = xincial;
    this->yinicial = yincial;


}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::movimentar()
{
    if(this->x < this->larguraLinha + this->xinicial && this->y <this->alturaLinha + this->yinicial && this->y == this->yinicial){
        this->x +=this->velocidade;

        // se move para a direita
    }
    else if(this->x >=this->larguraLinha + this->xinicial && this->y < this->alturaLinha + this->yinicial){
        this->y += this->velocidade;

        // se move para baixo
    }

    else if(this->x < this->xinicial && this->y > this->yinicial){
        this->y -= this->velocidade;
        // se move para cima
    }
    else {
        this->x -= this->velocidade;
        // se move para esquerda

    }


}

