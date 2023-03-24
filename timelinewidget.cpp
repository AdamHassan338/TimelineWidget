#include "timelinewidget.h"
#include "ui_timelinewidget.h"

TimelineWidget::TimelineWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimelineWidget)
{
    ui->setupUi(this);
}

TimelineWidget::~TimelineWidget()
{
    delete ui;
}

