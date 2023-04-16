#ifndef PLAYHEAD_H
#define PLAYHEAD_H

#include <QGraphicsLineItem>
#include "playheadhandler.h"

class Playhead : public QGraphicsLineItem
{

public:
    Playhead(qreal height);


    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void updatePos(QPointF p);
    static PlayheadHandler* handler;

private:
    bool m_pressed;
    QPointF m_lastpos;
    QRectF m_boundingRectOriginal;
    qreal m_height;



};
#endif // PLAYHEAD_H
