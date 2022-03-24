#include "paredfija.h"

paredfija::paredfija()
{
    this->posx=0;
    this->posy=0;
    this->lado=64;
    setPos(posx,posy);
}

paredfija::paredfija(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF paredfija::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void paredfija::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/imagen/Imagenes/bloque.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());

}
