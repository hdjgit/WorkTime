#include "loadactivitylistdatathread.h"
#include <QDebug>
#include "Domain/activitylist.h"
#include "Dao/activitylistdao.h"

LoadActivityListDataThread::LoadActivityListDataThread():mActivityList()
{

}


void LoadActivityListDataThread::run()
{
    qDebug()<<"LoadActivityListDataThread::run()";
    //mActivityList.clear();
    qDebug()<<"size:"<<mActivityList.size();
    //ActivityListDao().getAllActivityList();
    //mActivityList.append(lists);
    //qDebug()<<"size:"<<mActivityList.size();
    //qDebug()<<mActivityList;
    //emit dataLoaded();
}
