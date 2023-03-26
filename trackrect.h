#ifndef TRACKRECT_H
#define TRACKRECT_H

#include <QGraphicsRectItem>
class TrackRect : public QGraphicsRectItem
{
public:
    TrackRect(qreal x,qreal y,qreal w,qreal h);

private:


    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TRACKRECT_H
