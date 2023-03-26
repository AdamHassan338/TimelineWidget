#include "timelinewidget.h"
#include "ui_timelinewidget.h"
#include <QMouseEvent>

TimelineWidget::TimelineWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimelineWidget)
{
    ui->setupUi(this);
    scene = new TimelineScene(this);
    view = new TimelineView(this);
    view->setScene(scene);

    //scene->setSceneRect(view->rect());
    //scene->setSceneRect(scene->sceneRect());


    ui->verticalLayout->addWidget(view);
    view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ClipRect* clip = new ClipRect();
    clip->setRect(0,0,300,40);

    scene->addItem(clip);

    TrackRect* track = new TrackRect(0,0,view->mapToScene(view->width(),0).x()-1,40);
    //trackRects.push_back(new TrackRect(0,0,60,scene->width()));
    scene->addItem(track);

    playhead = new Playhead(scene->height()-1);
    scene->addItem(playhead);
    playhead->setPos(10,0);


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



