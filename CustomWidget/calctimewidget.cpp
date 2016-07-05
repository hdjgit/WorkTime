#include "calctimewidget.h"
#include <QDebug>
#include <QTimer>

CalcTimeWidget::CalcTimeWidget(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_StaticContents);
    //setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    mCircleColor=QColor(234,234,234);
    mTextColor=QColor(36,195,206);
    mBackgroundColor=QColor(255,255,255);
    mCircleRadius=110;
    mCircleWidth=6;

//    QPalette pal = palette();
//    pal.setColor(backgroundRole(), mBackgroundColor);
//    setPalette(pal);
    mTextWidth=135;
    mTextHeight=42;

    mMenuWidth=31;
    mMenuHeight=31;

    mCurrentStatus=CalcTimeWidget::STOPPED;
    mInitSeconds=2400;
    mTotalSeconds=mInitSeconds;
    mCalcTimer=0;
    calcTime();
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
    painter.setRenderHint(QPainter::Antialiasing,true);

    drawOuterCircle(painter);

    drawInnerCircle(painter);

    drawTimeText(painter);

    drawMenu(painter);
}

void CalcTimeWidget::drawOuterCircle(QPainter& painter)
{
    QPen pen;
    pen.setColor(mCircleColor);
    painter.setPen(pen);

    QBrush brush = getSolidBrush();
    brush.setColor(mCircleColor);
    //设置成填充的
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(mCircleRadius,mCircleRadius),mCircleRadius,mCircleRadius);
}

void CalcTimeWidget::drawTimeText(QPainter &painter)
{
    QPen pen;
    pen.setColor(mTextColor);
    painter.setPen(pen);

    //设置字体和大小，是否加粗
    QFont font = painter.font();
    font.setPixelSize(48);
    //font.setBold(true);
    font.setFamily("arial");
    painter.setFont(font);

    const QRect rectangle = QRect((mCircleRadius*2-mTextWidth)/2,mCircleRadius*2/3,mTextWidth,mTextHeight);
    QRect boundingRect;
    painter.drawText(rectangle, Qt::AlignCenter, getCurrentTime(), &boundingRect);
}



void CalcTimeWidget::drawMenu(QPainter &painter)
{
    QPen pen;
    pen.setColor(mTextColor);
    painter.setPen(pen);

    if(mCurrentStatus==CalcTimeWidget::STOPPED){
        drawRunningImg(painter);

    }else if(mCurrentStatus==CalcTimeWidget::RUNNING){
        drawStoppedImg(painter);

    }

}

void CalcTimeWidget::drawStoppedImg(QPainter &painter)
{
    int left=(mCircleRadius*2-mMenuWidth)/2;
    int top=mCircleRadius+30;
    QRect rect(left,top,mMenuWidth,mMenuHeight);

    painter.fillRect(rect,mTextColor);
}

void CalcTimeWidget::drawRunningImg(QPainter &painter)
{
    int left=(mCircleRadius*2-mMenuWidth)/2;
    int top=mCircleRadius+30;

    QPainterPath path;
    int triangleLeft=left+5;
    path.moveTo(triangleLeft,top);
    path.lineTo(triangleLeft,top+mMenuHeight);
    path.lineTo(left+mMenuWidth,top+mMenuHeight/2);

    QBrush brush = getSolidBrush();
    brush.setColor(mTextColor);
    //设置成填充的
    painter.setBrush(brush);
    painter.drawPath(path);
}

void CalcTimeWidget::start()
{
    mCurrentStatus=CalcTimeWidget::RUNNING;
    if(mCalcTimer==0){
        mCalcTimer=new QTimer(this);
        connect(mCalcTimer,SIGNAL(timeout()),this,SLOT(updateTime()));
        mCalcTimer->start(1000);
    }
}

void CalcTimeWidget::breakOff()
{
    mCurrentStatus=CalcTimeWidget::STOPPED;
}

QString CalcTimeWidget::getCurrentTime() const
{
    return QString("%1:%2").arg(mCurrentMin,2,10,QLatin1Char('0')).arg(mCurrentSeconds,2,10,QLatin1Char('0'));
    //return curTime.sprintf("%2d:%2d",mCurrentMin,mCurrentSeconds);
}

void CalcTimeWidget::drawInnerCircle(QPainter& painter)
{
    //使用不同的brush来使得
    QBrush centerBrush=getSolidBrush();
    centerBrush.setColor(mBackgroundColor);
    painter.setBrush(centerBrush);
    painter.drawEllipse(QPoint(mCircleRadius,mCircleRadius),mCircleRadius-mCircleWidth,mCircleRadius-mCircleWidth);
}



void CalcTimeWidget::mousePressEvent(QMouseEvent *ev)
{
    //qDebug()<<"mousePress";
    if(mCurrentStatus==CalcTimeWidget::RUNNING){

        breakOff();
    }else if(mCurrentStatus==CalcTimeWidget::STOPPED){

        start();
    }
    update();
}

// holds the recommended size for the widget
QSize CalcTimeWidget::sizeHint() const
{
    return QSize(mCircleRadius*2+2,mCircleRadius*2+2);
}

void CalcTimeWidget::calcTime()
{
    mCurrentMin=mTotalSeconds/60;
    mCurrentSeconds=mTotalSeconds%60;
}

void CalcTimeWidget::reCalcTime()
{
    mTotalSeconds-=1;
    mCurrentMin=mTotalSeconds/60;
    mCurrentSeconds=mTotalSeconds%60;
}

void CalcTimeWidget::updateTime()
{
    reCalcTime();
    update();
}

