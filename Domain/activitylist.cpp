#include "activitylist.h"

ActivityList::ActivityList()
{

}

int ActivityList::getPriority() const
{
    return priority;
}

void ActivityList::setPriority(int value)
{
    priority = value;
}

int ActivityList::getId() const
{
    return id;
}

void ActivityList::setId(int value)
{
    id = value;
}

QString ActivityList::getActivityName() const
{
    return activityName;
}

void ActivityList::setActivityName(const QString &value)
{
    activityName = value;
}

QString ActivityList::getAddTime() const
{
    return addTime;
}

void ActivityList::setAddTime(const QString &value)
{
    addTime = value;
}
