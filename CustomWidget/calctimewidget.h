#ifndef CALCTIMEWIDGET_H
#define CALCTIMEWIDGET_H

#include <QWidget>

#include <QPen>
#include <QPainter>
/*
 * 显示时间的控件
 */
class CalcTimeWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor circleColor READ circleColor WRITE setCircleColor)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor)
public:
    explicit CalcTimeWidget(QWidget *parent = 0);

    //set&get
    void setCircleColor(const QColor &color);
    QColor circleColor() const{return mCircleColor;}

    void setTextColor(const QColor &color);
    QColor textColor() const{return mTextColor;}
    void drawInnerCircle(QPainter& painter);
    void drawOuterCircle(QPainter& painter);
    void drawTimeText(QPainter& painter);
    void drawMenu(QPainter& painter);

    void drawStoppedImg(QPainter& painter);
    void drawRunningImg(QPainter& painter);

    //开启
    void start();
    //中断
    void breakOff();

    QString getCurrentTime() const;

    enum Status{
        //中断，等待开启
        STOPPED,
        //运行计算中
        RUNNING
    };

protected:
    void paintEvent(QPaintEvent* ev);
    void mousePressEvent(QMouseEvent* ev);
    QSize sizeHint() const;
    //更新时间，重新计算时间
    void reCalcTime();
    //根据总的秒数计算分钟以及秒数
    void calcTime();
signals:

public slots:
    void updateTime();
private:
    QColor mCircleColor;
    QColor mTextColor;
    int mCircleRadius;
    int mCircleWidth;
    QColor mBackgroundColor;
    QBrush getSolidBrush();
    int mTextWidth;
    int mTextHeight;
    int mMenuWidth;
    int mMenuHeight;
    Status mCurrentStatus;
    //初始时间
    int mInitSeconds;
    //总时间
    int mTotalSeconds;
    //显示分钟
    int mCurrentMin;
    //显示秒数
    int mCurrentSeconds;
    //计算时间的定时器
    QTimer* mCalcTimer;
};

#endif // CALCTIMEWIDGET_H
