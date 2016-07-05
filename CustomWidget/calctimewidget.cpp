#include "calctimewidget.h"
#include <QDebug>

CalcTimeWidget::CalcTimeWidget(QWidget *parent) : QWidget(parent)
{

}

void CalcTimeWidget::setCircleColor(const QColor &color){
    mCircleColor=color;
}

void CalcTimeWidget::setTextColor(const QColor &color){
    mTextColor=color;
}

void CalcTimeWidget::paintEvent(QPaintEvent *ev)
{
    qDebug()<<"paintEvent";
}

void CalcTimeWidget::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"mousePress";
}

