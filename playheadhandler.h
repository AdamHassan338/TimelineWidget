#ifndef PLAYHEADHANDLER_H
#define PLAYHEADHANDLER_H

#include <QObject>

class PlayheadHandler : public QObject
{
    Q_OBJECT
public:
    explicit PlayheadHandler(QObject *parent = nullptr);


    void emitSignal();

signals:
    void playheadMoved();
};

#endif // PLAYHEADHANDLER_H
