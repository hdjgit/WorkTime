#include "calctimewidget.h"
#include <QDebug>

CalcTimeWidget::CalcTimeWidget(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_StaticContents);
    //setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    mCircleColor=QColor(234,234,234);
    mTextColor=QColor(36,195,206);
    mBackgroundColor=QColor(255,255,255);
    mCircleRadius=110;
    mCircleWidth=10;

    QPalette pal = palette();
    pal.setColor(backgroundRole(), mBackgroundColor);
    setPalette(pal);
}

void CalcTimeWidget::setCircleColor(const QColor &color){
    mCircleColor=color;
}

void CalcTimeWidget::setTextColor(const QColor &color){
    mTextColor=color;
}

QBrush CalcTimeWidget::getSolidBrush()
{
    QBrush brush;
    //brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);

    return brush;
}

void CalcTimeWidget::paintEvent(QPaintEvent *ev)
{
    //qDebug()<<"paintEvent";
    QPainter painter(this);
    QPen pen;
    pen.setColor(mCircleColor);
    painter.setPen(pen);

    QBrush brush = getSolidBrush();
    brush.setColor(mCircleColor);
    //设置成填充的
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(mCircleRadius,mCircleRadius),mCircleRadius,mCircleRadius);

    pen.setColor(mBackgroundColor);
    //使用不同的brush来使得
    QBrush centerBrush=getSolidBrush();
    centerBrush.setColor(mBackgroundColor);
    painter.setBrush(centerBrush);
    painter.drawEllipse(QPoint(mCircleRadius,mCircleRadius),mCircleRadius-mCircleWidth,mCircleRadius-mCircleWidth);
}

void CalcTimeWidget::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"mousePress";
}

// holds the recommended size for the widget
QSize CalcTimeWidget::sizeHint() const
{
    return QSize(mCircleRadius*2+2,mCircleRadius*2+2);
}

