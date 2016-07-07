#include "dbutil.h"

DbUtil::DbUtil()
{

}
const QString DbUtil::DATABASE_CONNECT_NAME("WorkTimeConnect");
const QString DbUtil::DATABASE_NAME("WorkTime");
QSqlDatabase DbUtil::getDatabase(bool &success)
{
    QSqlDatabase db;
    if (!QSqlDatabase::contains(DbUtil::DATABASE_CONNECT_NAME)) {
        db = QSqlDatabase::addDatabase("QMYSQL", DbUtil::DATABASE_CONNECT_NAME);
        db.setDatabaseName(DbUtil::DATABASE_NAME);
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("huangduanji");
    } else {
        db = QSqlDatabase::database(DbUtil::DATABASE_CONNECT_NAME, true);
    }
    if (!db.isOpen()) {
        bool result = db.open();
        if(result){
            success=true;
        }else{
            success=false;
        }
    }else{
        success=false;
    }
    return db;
}

void DbUtil::removeDatabase()
{
    QSqlDatabase::removeDatabase(DbUtil::DATABASE_CONNECT_NAME);
}
