#ifndef ACTIVITYLIST_H
#define ACTIVITYLIST_H

#include <QString>
class ActivityList
{
public:
    ActivityList();

    int getPriority() const;
    void setPriority(int value);

    int getId() const;
    void setId(int value);

    QString getActivityName() const;
    void setActivityName(const QString &value);

    QString getAddTime() const;
    void setAddTime(const QString &value);

private:
    int id;
    QString activityName;
    QString addTime;
    int priority;
};

#endif // ACTIVITYLIST_H
