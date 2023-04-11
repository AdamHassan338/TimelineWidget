#include "trackrect.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

TrackRect::TrackRect(qreal x,qreal y,qreal w,qreal h)
{
    setZValue(-1);
    //w = scene()->width();
    setRect(0,0,w,h);
    setPos(x,y);

}

void TrackRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)

    painter->save();
    QList<qreal> dashes;
    dashes << 2<< 2;
    if(scene()->width() > scene()->views()[0]->rect().width()){
        setRect(0,0,scene()->width()-1,40);
    }else{
        setRect(0,0,scene()->views()[0]->rect().width()-1,40);
    }


    Q_UNUSED(widget);
    QBrush brush(Qt::SolidPattern);
    QPen pen(Qt::black, 2);
    brush.setColor(Qt::lightGray);
    //pen.setStyle(Qt::DashLine);
    //pen.setDashPattern(dashes);
    brush.setStyle(Qt::NoBrush);
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawRect(rect());

    painter->restore();

}
