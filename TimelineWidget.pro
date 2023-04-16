QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clipitemhandler.cpp \
    cliprect.cpp \
    main.cpp \
    playhead.cpp \
    playheadhandler.cpp \
    timelinescene.cpp \
    timelineview.cpp \
    timelinewidget.cpp \
    trackrect.cpp

HEADERS += \
    Clip.h \
    Track.h \
    clipitemhandler.h \
    cliprect.h \
    common.h \
    playhead.h \
    playheadhandler.h \
    timelinescene.h \
    timelineview.h \
    timelinewidget.h \
    trackrect.h

FORMS += \
    timelinewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
