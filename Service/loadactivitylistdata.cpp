#include "loadactivitylistdata.h"
#include "Dao/activitylistdao.h"
#include <QList>
#include <QDebug>

LoadActivityListData::LoadActivityListData(QObject *parent) : QObject(parent)
{

}

void LoadActivityListData::loadData()
{
    QList<ActivityList*> list=ActivityListDao().getAllActivityList();
    qDebug()<<list.size();
    emit dataLoaded(list);
}
