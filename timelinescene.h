#ifndef TIMELINESCENE_H
#define TIMELINESCENE_H

#include <QGraphicsScene>

class TimelineScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TimelineScene(QObject *parent = nullptr);

signals:

};

#endif // TIMELINESCENE_H
