#ifndef ACTIVITYLISTDAO_H
#define ACTIVITYLISTDAO_H

#include "Domain/activitylist.h"
class ActivityListDao
{
public:
    ActivityListDao();
    static bool saveActivityList(ActivityList &activityList);

};

#endif // ACTIVITYLISTDAO_H
