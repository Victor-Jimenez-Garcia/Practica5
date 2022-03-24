#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class enemigos: public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
    int vel;
public:
    enemigos();
    enemigos(int x, int y, int lado, int vel);

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    bool evaluarColision();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int getPosx() const;
    int getPosy() const;
};

#endif // ENEMIGOS_H
