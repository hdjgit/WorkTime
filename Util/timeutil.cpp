#include "timeutil.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
TimeUtil::TimeUtil()
{

}

QString TimeUtil::getCurrentTime()
{

    return QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm");
}
