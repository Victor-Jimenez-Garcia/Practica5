#ifndef PAREDFIJA_H
#define PAREDFIJA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class paredfija: public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
public:
    paredfija();
    paredfija(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // PAREDFIJA_H
