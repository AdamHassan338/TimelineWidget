#include "timelinewidget.h"
#include "ui_timelinewidget.h"
#include "clipitemhandler.h"
#include <QMouseEvent>
#include <QRectF>
#include <QDebug>

ClipItemHandler* ClipRect::handler = new ClipItemHandler();
TimelineWidget::TimelineWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimelineWidget)
{
    trackHeight = 40;
    clipHeight= 40;

    ui->setupUi(this);
    scene = new TimelineScene(this);
    view = new TimelineView(this);
    view->frameRect();
    view->setScene(scene);
    scene->setSceneRect(view->rect());



    //scene->setSceneRect(view->rect());
    //scene->setSceneRect(scene->sceneRect());


    ui->verticalLayout->addWidget(view);
    view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ClipRect* clip = new ClipRect();
    clip->setRect(0,0,300,clipHeight);
    connect(ClipRect::handler,&ClipItemHandler::newTrack,this,&TimelineWidget::addTrack);

    scene->addItem(clip);

    ClipRect* clip2 = new ClipRect();
    clip2->setRect(0,0,100,clipHeight);

    clip2->setPos(0,trackHeight*1);
    scene->addItem(clip2);


    TrackRect* track = new TrackRect(0,0,scene->width()-1,trackHeight);
    trackRects.push_back(track);
    scene->addItem(track);

    TrackRect* track2 = new TrackRect(0,0,view->mapToScene(view->width(),0).x()-1,trackHeight);
    track2->setPos(0,trackHeight*1);
    trackRects.push_back(track);
    scene->addItem(track2);

    playhead = new Playhead(scene->height()-1);
    scene->addItem(playhead);
    playhead->setPos(10,0);


}

void TimelineWidget::addTrack(int x)
{
    Q_UNUSED(x);
    TrackRect* track = new TrackRect(0,0,scene->width()-1,trackHeight);
    track->setPos(0,trackRects.size()*trackHeight);
    trackRects.push_back(track);
    scene->addItem(track);

}

void TimelineWidget::mousePressEvent(QMouseEvent *event)
{
   QPoint widgetPoint = event->pos();
   QPointF scenePoint = view->mapToScene(view->mapFromParent(widgetPoint));
   //search items in scene
   for(const QGraphicsItem* item : scene->items()){
       if(item->contains(scenePoint)){
       }
       else{
           playhead->updatePos(scenePoint);
           m_playheadPressed = true;
       }
   }

}

void TimelineWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_playheadPressed = false;

}

void TimelineWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_playheadPressed){
        QPoint widgetPoint = event->pos();
        QPointF scenePoint = view->mapToScene(view->mapFromParent(widgetPoint));
        playhead->updatePos(scenePoint);
    }
}

TimelineWidget::~TimelineWidget()
{
    delete ui;
}



