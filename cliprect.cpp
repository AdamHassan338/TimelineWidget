#include "cliprect.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <math.h>
#include "common.h"
#include <QFileInfo>

ClipRect::ClipRect()
{
    //setFlag(ItemIsMovable);
    if(!handler){
        ClipRect::handler = new ClipItemHandler;
    }
    m_mousePressed = false;
    m_name = "No Name";

}

ClipRect::ClipRect(QString path) : m_mousePressed(false),m_path(path)
{
    QFileInfo file(path);
    m_name = file.fileName();
}

double ClipRect::seconds() const
{
    return m_seconds;
}

void ClipRect::setSeconds(double newSeconds)
{
    m_seconds = newSeconds;
}

double ClipRect::framerate() const
{
    return m_framerate;
}

void ClipRect::setFramerate(double newFramerate)
{
    m_framerate = newFramerate;
}

int ClipRect::frames() const
{
    return m_frames;
}

void ClipRect::setFrames(int newFrames)
{
    m_frames = newFrames;
}

const QString &ClipRect::name() const
{
    return m_name;
}

int ClipRect::track() const
{
    return m_track;
}

void ClipRect::setTrack(int newTrack)
{
    m_track = newTrack;
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
    QPointF oldPos = pos();
    // need to know track height
    // ypos % trackheight = track number

    if(m_mousePressed){
        qreal y = std::fmod(mousePos.y(), trackHeight);
        qreal x = mousePos.x() + m_mouseDelta.x();

        //if moved outside of scene, 5 is for sensistivity, add track
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

        //Collision Detection
        int xp = 0;
        for(QGraphicsItem* item : scene()->items()){

            //Is cliprect ?
            ClipRect* clip = dynamic_cast<ClipRect*>(item);
            //is the same Cliprect
            if(clip && clip != this){
                QRectF marginRect = rect().adjusted(0, 3, 0, -3);
                QGraphicsRectItem* marginRectItem = new QGraphicsRectItem(marginRect);
                marginRectItem->setPos(pos());
                if(clip->collidesWithItem(marginRectItem,Qt::IntersectsItemBoundingRect)){
                    setPos(oldPos);
                }
            }


        }

        qDebug() << xp;

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
    painter->drawText(rect(),m_name);
    //QString t = &"Track: " [ m_track];
    QString t = "track 1";
    painter->drawText(rect().topLeft() - QPoint(0,-30),t);



    painter->restore();


}
