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
    double currentTime();
    int currentFrame();

    int frameUnderPlayehead();

    ~TimelineWidget();

private  slots:
    void addTrack(int x);
    void addClip(QString filename,int frames,double framerate,int track,int x);
    void underPlayhead();
    int getFrame(ClipRect* clip);
private:
    Ui::TimelineWidget *ui;
    TimelineScene* scene;
    TimelineView* view;
    Playhead* playhead;
    std::vector<Track> tracks;
    std::vector<TrackRect*> trackRects;
    std::vector<ClipRect*> clipRects;
    qreal playheadPos;

    //float trackHeight;
    //float clipHeight;

    bool m_playheadPressed = false;





    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // TIMELINEWIDGET_H
