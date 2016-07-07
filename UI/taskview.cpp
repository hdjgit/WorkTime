#include "taskview.h"
#include "Util/dbutil.h"
#include "Domain/activitylist.h"
#include <QDebug>
TaskView::TaskView(QWidget *parent) : QWidget(parent)
{
    //bool connected=mDbUtil->createConnection();
    //qDebug()<<connected;
    //execQuery方法测试
//    QSqlQuery query=mDbUtil->execQuery("select * from ActivityList");
//    while(query.next()){
//        int id=query.value(0).toInt();
//        qDebug()<<id;
//    }
    ActivityList list("name1","addTime1",12);
    ActivityListDao::saveActivityList(list);
}
