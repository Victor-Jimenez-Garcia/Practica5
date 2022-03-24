#include "enemigos.h"

int enemigos::getPosx() const
{
    return posx;
}

int enemigos::getPosy() const
{
    return posy;
}

enemigos::enemigos()
{
    this->posx=50;
    this->posy=25;
    this->lado=25;
    this->vel=5;
    setPos(posx,posy);

}
enemigos::enemigos(int x, int y, int lado, int vel)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    this->vel=vel;
    setPos(posx,posy);
}
QRectF enemigos::boundingRect() const
{
    return QRectF(0,0,25,25);
}

void enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/imagen/Imagenes/valcmuerte1.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
void enemigos::moveUp()
{
    this->posy -= vel;
    setPos(posx,posy);
}

void enemigos::moveDown()
{
    this->posy += vel;
    setPos(posx,posy);
}

void enemigos::moveLeft()
{
    this->posx -= vel;
    setPos(posx,posy);
}

void enemigos::moveRight()
{
    this->posx += vel;
    setPos(posx,posy);
}
