#ifndef TASKVIEW_H
#define TASKVIEW_H

#include <QWidget>
#include "Util/dbutil.h"
#include "Dao/activitylistdao.h"
#include <QListWidget>
#include <QVBoxLayout>
#include "CustomWidget/customlistlayout.h"
#include <QList>
class QScrollArea;
class AddTaskDialog;
class TaskView : public QWidget
{
    Q_OBJECT
public:
    explicit TaskView(QWidget *parent = 0);
    ~TaskView();
    //QListWidget* initListWidget();
    //QListView* initListView();
    //初始化滚动区域
    void initScrollArea();
    //初始化ListLayout
    void initListLayout();
signals:
    void startLoadData();
public slots:
    void createAddTaskDialog();
    void updateList(QList<ActivityList*> lists);
private:
    //ActivityListDao* mActivityListDao;
    QScrollArea* mScrollArea;
    QWidget* mActivityListWidget;
    CustomListLayout* mCustomListLayout;
    //AddTaskDialog* mAddTaskDialog;
    QList<ActivityList*> mActivityLists;
    QThread mLoadDataThread;
};

#endif // TASKVIEW_H
