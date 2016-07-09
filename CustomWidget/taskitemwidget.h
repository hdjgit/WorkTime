#ifndef TASKITEMWIDGET_H
#define TASKITEMWIDGET_H

#include <QWidget>
class QCheckBox;
class TaskItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskItemWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QCheckBox* mCheckBox;
};

#endif // TASKITEMWIDGET_H
