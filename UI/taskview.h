#ifndef TASKVIEW_H
#define TASKVIEW_H

#include <QWidget>
#include "Util/dbutil.h"
class TaskView : public QWidget
{
    Q_OBJECT
public:
    explicit TaskView(QWidget *parent = 0);

signals:

public slots:
private:
    DbUtil* mDbUtil;
};

#endif // TASKVIEW_H
