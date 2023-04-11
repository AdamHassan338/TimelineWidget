#include "timelinescene.h"

TimelineScene::TimelineScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

void TimelineScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{


    // if scene is larger than defualt width, auto update width
    if(itemsBoundingRect().width() > sceneRect().width() && intialSize){
        QRectF newRect;
        setSceneRect(newRect);
        intialSize = false;

    }

     QGraphicsScene::mouseMoveEvent(event);
}
