#include "trackrect.h"
#include <QPainter>
#include <QGraphicsScene>

TrackRect::TrackRect(qreal x,qreal y,qreal w,qreal h)
{
    setZValue(-1);
    //w = scene()->width();
    setRect(0,0,w,h);
    setPos(x,y);

}

void TrackRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QGraphicsRectItem::paint(painter,option,widget);

    painter->save();

    setRect(0,0,scene()->width()-1,40);
    Q_UNUSED(widget);
    QBrush brush(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    brush.setStyle(Qt::NoBrush);
    painter->setBrush(brush);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawRect(rect());

    painter->restore();

}
