#ifndef TASKITEMWIDGET_H
#define TASKITEMWIDGET_H

#include <QWidget>
class QCheckBox;
class QLabel;

class TaskItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskItemWidget(QWidget *parent = 0);

    void initCheckBox();

    void setTaskName(QString taskName);

signals:

public slots:
private:
    QCheckBox* mCheckBox;
    QLabel* mTaskName;
};

#endif // TASKITEMWIDGET_H
