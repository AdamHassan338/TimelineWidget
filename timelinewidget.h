#ifndef TIMELINEWIDGET_H
#define TIMELINEWIDGET_H

#include <QWidget>
#include "Track.h"
#include "timelineview.h"
#include "timelinescene.h"
#include "cliprect.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class TimelineWidget; }
QT_END_NAMESPACE

class TimelineWidget : public QWidget
{
    Q_OBJECT

public:
    TimelineWidget(QWidget *parent = nullptr);
    void addClip(QString name,int frames,double start);
    ~TimelineWidget();

private:
    Ui::TimelineWidget *ui;
    TimelineScene* scene;
    TimelineView* view;
    std::vector<Track> tracks;
    float trackWidth;
    float clipWidth;




};
#endif // TIMELINEWIDGET_H
