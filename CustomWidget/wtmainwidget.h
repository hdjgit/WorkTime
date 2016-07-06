#ifndef WTMAINWIDGET_H
#define WTMAINWIDGET_H

#include <QWidget>

class QTabWidget;
class ClockView;
class TaskView;
class WTMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WTMainWidget(QWidget *parent = 0);
    QSize sizeHint() const;
    void initTab();

signals:

public slots:
private:
    QTabWidget* mTabWidget;
    ClockView* mClockView;
    TaskView* mTaskView;
};

#endif // WTMAINWIDGET_H
