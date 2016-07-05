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
protected:
    void paintEvent(QPaintEvent* ev);
    void mousePressEvent(QMouseEvent* ev);
    QSize sizeHint() const;

signals:

public slots:
private:
    QColor mCircleColor;
    QColor mTextColor;
    int mCircleRadius;
    int mCircleWidth;
    QColor mBackgroundColor;
    QBrush getSolidBrush();
};

#endif // CALCTIMEWIDGET_H
