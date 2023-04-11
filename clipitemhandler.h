#ifndef CLIPITEMHANDLER_H
#define CLIPITEMHANDLER_H

#include <QObject>

class ClipItemHandler : public QObject
{
    Q_OBJECT
public:
    explicit ClipItemHandler(QObject *parent = nullptr);
    void emitnewTrack(int trackNumber);

signals:
    int newTrack(int trackNumber);

};

#endif // CLIPITEMHANDLER_H
