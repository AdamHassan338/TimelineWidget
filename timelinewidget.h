#ifndef TIMELINEWIDGET_H
#define TIMELINEWIDGET_H

#include <QWidget>
#include "Track.h"
#include "timelineview.h"
#include "timelinescene.h"
#include "cliprect.h"
#include "trackrect.h"
#include "playhead.h"
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
    Playhead* playhead;
    std::vector<Track> tracks;
    std::vector<TrackRect*> trackRects;
    float trackWidth;
    float clipWidth;

    bool m_playheadPressed = false;





    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};
#endif // TIMELINEWIDGET_H
