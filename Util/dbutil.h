#ifndef DBUTIL_H
#define DBUTIL_H
#include <QtSql>
#include <QObject>

class DbUtil:QObject
{
    Q_OBJECT
public:
    DbUtil(QObject *parent = 0);
    bool createConnection();
    QSqlQuery execQuery(QString sql);
    void showError();
private:
    QSqlDatabase mDb;
};

#endif // DBUTIL_H
