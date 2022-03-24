#ifndef PAREDDEST_H
#define PAREDDEST_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class pareddest: public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
public:
    pareddest();
    pareddest(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // PAREDDEST_H
