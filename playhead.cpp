#include "playhead.h"
#include <QPainter>
#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

Playhead::Playhead(qreal height) : QGraphicsLineItem()
{
    setLine(0,0,0,height);
    m_height = height;
    m_boundingRectOriginal = boundingRect();

    setZValue(100);
    m_pressed = false;
}

void Playhead::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Q_UNUSED(option);Q_UNUSED(widget);
    setLine(0,0,0,scene()->height()-1);

    painter->save();
    QPen pen = QPen(Qt::red,3);
    painter->setPen(pen);
    painter->drawLine(line());

    painter->restore();
}

QRectF Playhead::boundingRect() const
{
    QPoint topLeft = QPoint(-5,0);
    QPoint bottomRight = QPoint(5,-m_height);
    //return QRectF(topLeft,bottomRight);
    return QGraphicsLineItem::boundingRect();
}

void Playhead::updatePos(QPointF p)
{
    setPos(p.x(),0);
}

void Playhead::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_pressed = true;
    m_lastpos = event->scenePos();
    //line().setLine(m_lastpos.x(),0,m_lastpos.x(),scene()->width() -1);
    qDebug() << "playhead";
}

void Playhead::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_pressed){
        m_lastpos = event->scenePos();
        //line().setLine(m_lastpos.x(),0,m_lastpos.x(),scene()->width() -1);
        setPos(m_lastpos.x(),0);
        qDebug() << "playhead move";
    }

}

void Playhead::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //Q_UNUSED(event)
    m_pressed= false;

}


