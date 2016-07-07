#include "activitylistdao.h"
#include "Util/dbutil.h"
ActivityListDao::ActivityListDao()
{

}

bool ActivityListDao::saveActivityList(ActivityList &activityList)
{
    bool success=false;
    QSqlDatabase db=DbUtil::getDatabase(success);
    if(success){
        QSqlQuery query(db);
        QString sql="INSERT INTO activitylist (activity_name,add_time,priority) VALUES('%1','%2','%3');";
        sql=sql.arg(activityList.getActivityName()).arg(activityList.getAddTime()).arg(activityList.getPriority());
        success=query.exec(sql);
        if(!success){
            qDebug()<<query.lastError().text();
        }
        return success;
    }else{
        return false;
    }
}
