#ifndef ACTIVITYLISTDAO_H
#define ACTIVITYLISTDAO_H

#include "Domain/activitylist.h"
#include <QList>
#include <QString>
class ActivityListDao
{
public:
    ActivityListDao();
    bool saveActivityList(ActivityList &activityList);
    QList<ActivityList*> getAllActivityList();
    const static QString ACTIVITY_LIST_DIR;
    const static QString ACTIVITY_LIST_PATH;
    const static QString ACTIVITY_LIST_SPLIT;
};

#endif // ACTIVITYLISTDAO_H
