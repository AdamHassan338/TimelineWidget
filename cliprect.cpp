#include "cliprect.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <math.h>

ClipRect::ClipRect()
{
    //setFlag(ItemIsMovable);
    m_mousePressed = false;

}

void ClipRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_mousePressed = true;
        m_startPos = event->scenePos();
        m_startClipPos = pos();
        m_mouseDelta = pos() - m_startPos;
        event->accept();
    }else{
        event->ignore();
    }
    qDebug() << "clicked on rect\n" << scenePos();
}

void ClipRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF mousePos = event->scenePos();

    if(m_mousePressed){
        //QPointF oldPos = pos();
        //fix this
        if(std::fmod(mousePos.y(),trackWidth) != 0){
            QPointF newPos = mousePos + m_mouseDelta;
            setPos(newPos.x(),pos().y());
        }else{
            qreal y = mousePos.y() / trackWidth;
            qreal x = (mousePos + m_mouseDelta).x();
            setPos(x,y*trackWidth);
        }




    }
    qDebug() << mousePos.y() / trackWidth;
    event->accept();
}

void ClipRect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mousePressed = false;
    event->accept();

}

void ClipRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->save();
    QBrush brush = QBrush(Qt::gray);
    QPen pen = QPen();
    pen.setColor(Qt::darkGray);

    pen.setWidth(2);


    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(rect());


    painter->restore();


}
