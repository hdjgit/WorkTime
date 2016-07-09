#ifndef LOADACTIVITYLISTDATATHREAD_H
#define LOADACTIVITYLISTDATATHREAD_H

#include <QThread>
#include <QList>
class ActivityList;

class LoadActivityListDataThread: public QThread
{
    Q_OBJECT
public:
    LoadActivityListDataThread();
signals:
    void dataLoaded();
protected:
    void run();
private:
    QList<ActivityList*> mActivityList;
};

#endif // LOADACTIVITYLISTDATATHREAD_H
