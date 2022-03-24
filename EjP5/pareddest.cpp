#include "pareddest.h"

pareddest::pareddest()
{
    this->posx=0;
    this->posy=0;
    this->lado=64;
    setPos(posx,posy);
}

pareddest::pareddest(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF pareddest::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void pareddest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/imagen/Imagenes/ladrillo.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
