#include "timelineview.h"

TimelineView::TimelineView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void TimelineView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void TimelineView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void TimelineView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}
