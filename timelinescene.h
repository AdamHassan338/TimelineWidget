#ifndef TIMELINESCENE_H
#define TIMELINESCENE_H

#include <QGraphicsScene>
#include <QMimeData>

class TimelineScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TimelineScene(QObject *parent = nullptr);
    bool intialSize = true;

signals:


    // QGraphicsScene interface
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // TIMELINESCENE_H
