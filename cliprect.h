#ifndef CLIPRECT_H
#define CLIPRECT_H

#include <QGraphicsRectItem>
#include <clipitemhandler.h>

class ClipRect : public QGraphicsRectItem
{
public:
    explicit ClipRect();
    explicit ClipRect(QString path);
    static ClipItemHandler* handler;
    static void sethandler();
    QString getName(){return m_name;}

    // QGraphicsItem interface
private:



    bool m_mousePressed;
    QPointF m_startPos;
    QPointF m_startClipPos;
    qreal m_clipPos;
    QPointF m_mouseDelta;
    QString m_name;
    QString m_path;
    int m_track;

    //data
    int m_frames;
    double m_framerate;
    double m_seconds;


    int newTrack(int trackNumber);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;




    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int track() const;
    void setTrack(int newTrack);
    const QString &name() const;
    int frames() const;
    void setFrames(int newFrames);
    double framerate() const;
    void setFramerate(double newFramerate);
    double seconds() const;
    void setSeconds(double newSeconds);
};



#endif // CLIPRECT_H
