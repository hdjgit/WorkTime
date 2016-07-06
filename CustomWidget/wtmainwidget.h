#ifndef WTMAINWIDGET_H
#define WTMAINWIDGET_H

#include <QWidget>

class QTabWidget;
class ClockView;
class WTMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WTMainWidget(QWidget *parent = 0);
    QSize sizeHint() const;
signals:

public slots:
private:
    QTabWidget* mTabWidget;
    ClockView* mClockView;
};

#endif // WTMAINWIDGET_H
