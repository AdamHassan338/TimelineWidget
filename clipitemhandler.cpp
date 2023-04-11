#include "clipitemhandler.h"
#include <QDebug>
ClipItemHandler::ClipItemHandler(QObject *parent)
    : QObject{parent}
{

}

void ClipItemHandler::emitnewTrack(int trackNumber)
{
    emit newTrack(trackNumber);
}
