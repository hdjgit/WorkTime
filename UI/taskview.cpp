#include "taskview.h"
#include "Util/dbutil.h"
#include <QDebug>
TaskView::TaskView(QWidget *parent) : QWidget(parent)
{
    mDbUtil=new DbUtil(this);
    //bool connected=mDbUtil->createConnection();
    //qDebug()<<connected;

    QSqlQuery query=mDbUtil->execQuery("select * from ActivityList");
    while(query.next()){
        int id=query.value(0).toInt();
        qDebug()<<id;
    }
}
