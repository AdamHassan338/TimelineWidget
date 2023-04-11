#include "cliprect.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <math.h>

ClipRect::ClipRect()
{
    //setFlag(ItemIsMovable);
    if(!handler){
        ClipRect::handler = new ClipItemHandler;
    }
    m_mousePressed = false;

}



void ClipRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_mousePressed = true;
        m_startPos = event->scenePos();
        m_startClipPos = pos();
        m_mouseDelta = pos() - m_startPos;
        //event->accept();
    }else{
        //event->ignore();
    }
    qDebug() << "clicked on rect\n" << scenePos();
}

void ClipRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF mousePos = event->scenePos();

    // need to know track height
    // ypos % trackheight = track number

    if(m_mousePressed){
        qreal y = std::fmod(mousePos.y(), trackHeight);
        qreal x = mousePos.x() + m_mouseDelta.x();

        //if moved outside of scene
        if(mousePos.y() + 5 >scene()->itemsBoundingRect().height()){
            ClipRect::handler->emitnewTrack((int)y);
        }
        y = (mousePos.y() - y);

        if(x>0){
            setX(x);
        }
        if(y>=0){
            setY(y);
        }


        //qDebug() << y;

    }


    //event->accept();
}

void ClipRect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    m_mousePressed = false;
    //event->accept();

}

void ClipRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);Q_UNUSED(widget);
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
