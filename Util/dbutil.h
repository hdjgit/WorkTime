#ifndef DBUTIL_H
#define DBUTIL_H
#include <QtSql>

class DbUtil
{
public:
    DbUtil();
    static QSqlDatabase getDatabase(bool &success);
    static const QString DATABASE_CONNECT_NAME;
    static const QString DATABASE_NAME;
    static void removeDatabase();
};

#endif // DBUTIL_H
