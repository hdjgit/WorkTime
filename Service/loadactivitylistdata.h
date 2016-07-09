#ifndef LOADACTIVITYLISTDATA_H
#define LOADACTIVITYLISTDATA_H

#include <QObject>
#include <QList>
#include "Domain/activitylist.h"

class LoadActivityListData : public QObject
{
    Q_OBJECT
public:
    explicit LoadActivityListData(QObject *parent = 0);
public slots:
    void loadData();
signals:
    void dataLoaded(QList<ActivityList*> lists);
public slots:
};

#endif // LOADACTIVITYLISTDATA_H
