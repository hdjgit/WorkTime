#include "dbutil.h"
#include <QMessageBox>
#include <QtSql/QSqlError>
DbUtil::DbUtil(QObject *parent):QObject(parent)
{

}

bool DbUtil::createConnection()
{
    mDb=QSqlDatabase::addDatabase("QMYSQL");
    mDb.setHostName("127.0.0.1");
    mDb.setUserName("root");
    mDb.setPassword("huangduanji");
    mDb.setDatabaseName("WorkTime");
    if(!mDb.open()){
        showError();
        return false;
    }
    return true;
}

QSqlQuery DbUtil::execQuery(QString sql)
{
    if(createConnection()){
        QSqlQuery query(mDb);
        query.exec(sql);
        return query;
    }else{
        showError();
        return QSqlQuery();
    }
}

void DbUtil::showError()
{
    QMessageBox::critical(0,QObject::tr("Database Error"),
                          mDb.lastError().text());
}
