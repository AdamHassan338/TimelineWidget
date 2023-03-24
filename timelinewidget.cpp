#include "timelinewidget.h"
#include "ui_timelinewidget.h"

TimelineWidget::TimelineWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimelineWidget)
{
    ui->setupUi(this);
    scene = new TimelineScene(this);
    view = new TimelineView(this);
    view->setScene(scene);


    ui->verticalLayout->addWidget(view);
    view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ClipRect* clip = new ClipRect();
    clip->setRect(0,0,100,40);

    scene->addItem(clip);

}

TimelineWidget::~TimelineWidget()
{
    delete ui;
}

