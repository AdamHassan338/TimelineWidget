#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QGraphicsView>
#include <QTimer>

class TimelineView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit TimelineView(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;



    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

signals:
    void newClip(QString filename,int frames,double framerate,int track,int x);

private:
    bool m_pressed;

    qreal m_zoomX;

    QTimer m_scrollTimer;
    QPoint m_lastDragPos;

    void startAutoScroll();
    void stopAutoScroll();
    void scrollIfNecessary();


private slots:
    void onScrollTimerTimeout();







};

#endif // TIMELINEVIEW_H
