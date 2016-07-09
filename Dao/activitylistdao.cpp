#include "activitylistdao.h"
#include "Util/dbutil.h"
#include <QList>
const QString ActivityListDao::ACTIVITY_LIST_DIR("data/activityData");
const QString ActivityListDao::ACTIVITY_LIST_PATH("data/activityData/activityList.txt");
const QString ActivityListDao::ACTIVITY_LIST_SPLIT("#");
ActivityListDao::ActivityListDao()
{
    QDir fileDir(ActivityListDao::ACTIVITY_LIST_DIR);
    if(!fileDir.exists()){
        qDebug()<<"dir not exits";
        QDir().mkpath(ActivityListDao::ACTIVITY_LIST_DIR);
    }
}

bool ActivityListDao::saveActivityList(ActivityList &activityList)
{
    qDebug()<<"saveActivityList";
    QFile file(ActivityListDao::ACTIVITY_LIST_PATH);
    if(file.open(QIODevice::Append)){
        QTextStream out(&file);
        out<<activityList.getActivityName()
          <<ActivityListDao::ACTIVITY_LIST_SPLIT
          <<activityList.getAddTime()
            <<ActivityListDao::ACTIVITY_LIST_SPLIT
         <<activityList.getPriority()
        <<"\n";
        file.close();
        return true;
    }else{
        qDebug()<<"open error:"<<file.errorString();

        return false;
    }
    //out<<"new data"<<"\n";
    //out<<"new data"<<"\n";
//    if(!file.open(QIODevice::WriteOnly)){
//        qDebug()<<"open error:"<<file.errorString();
//    }
    return true;
//    bool success=false;
//    QSqlDatabase db=DbUtil::getDatabase(success);
//    if(success){
//        QSqlQuery query(db);
//        QString sql="INSERT INTO activitylist (activity_name,add_time,priority) VALUES('%1','%2','%3');";
//        sql=sql.arg(activityList.getActivityName()).arg(activityList.getAddTime()).arg(activityList.getPriority());
//        success=query.exec(sql);
//        if(!success){
//            qDebug()<<query.lastError().text();
//        }
//        return success;
//    }else{
//        return false;
//    }

}

QList<ActivityList*> ActivityListDao::getAllActivityList()
{
    QFile file(ActivityListDao::ACTIVITY_LIST_PATH);
    if(file.open(QIODevice::ReadOnly)){
//        QTextStream in(&file);
//        QList<ActivityList*> lists;
//        while(!in.atEnd()){
//            QString line=in.readLine();
//            QStringList activityListData=line.split(ActivityListDao::ACTIVITY_LIST_SPLIT);
//            QString activityName=activityListData.takeFirst();
//            QString addTime=activityListData.takeFirst();
//            int priority=activityListData.takeFirst().toInt();
//            ActivityList* activityList=new ActivityList(activityName,addTime,priority);
//            lists.append(activityList);
//        }
//        file.close();
//        return lists;
        return QList<ActivityList*>();
    }else{
        return QList<ActivityList*>();
    }
//    bool success;
//    QSqlDatabase db=DbUtil::getDatabase(success);
//    QSqlQuery query(db);
//    QString sql="SELECT * FROM ActivityList;";
//    query.exec(sql);
//    if(query.isActive()){
//        ActivityList* activityList;
//        QList<ActivityList*> qList;
//        while(query.next()){
//            activityList=new ActivityList(query.value(1).toString(),query.value(2).toString(),query.value(3).toInt());
//            qList.append(activityList);
//        }
//        return qList;
//    }else{
//        qDebug()<<query.lastError().text();
//        return QList<ActivityList*>();
//    }


}
