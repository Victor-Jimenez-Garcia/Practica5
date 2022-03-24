#include "personaje.h"

int personaje::getPosx() const
{
    return posx;
}

int personaje::getPosy() const
{
    return posy;
}

personaje::personaje()
{
    this->posx=25;
    this->posy=25;
    this->lado=25;
    this->vel=5;
    setPos(posx,posy);

}

personaje::personaje(int x, int y, int lado, int vel)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    this->vel=vel;
    setPos(posx,posy);
}

QRectF personaje::boundingRect() const
{
    return QRectF(0,0,25,25);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/imagen/Imagenes/frontal.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void personaje::moveUp()
{
    this->posy -= vel;
    setPos(posx,posy);
}

void personaje::moveDown()
{
    this->posy += vel;
    setPos(posx,posy);
}

void personaje::moveLeft()
{
    this->posx -= vel;
    setPos(posx,posy);
}

void personaje::moveRight()
{
    //QPixmap pxMap(":/imagen/Imagenes/derecha.png");
    this->posx += vel;
    setPos(posx,posy);
}

