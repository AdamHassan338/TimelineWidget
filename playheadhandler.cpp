#include "playheadhandler.h"

PlayheadHandler::PlayheadHandler(QObject *parent)
    : QObject{parent}
{

}

void PlayheadHandler::emitSignal()
{
    emit playheadMoved();
}
