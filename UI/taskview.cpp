#include "taskview.h"
#include "Util/dbutil.h"
#include "Domain/activitylist.h"
#include <QDebug>
#include <QListView>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include "CustomWidget/taskitemwidget.h"
#include "Dialog/addtaskdialog.h"
#include <QThread>
#include "Thread/loadactivitylistdatathread.h"
#include "Service/loadactivitylistdata.h"
//QListWidget * TaskView::initListWidget()
//{
//    QListWidget* listWidget=new QListWidget;
//    QLineEdit* lineEdit=new QLineEdit;
//    QListWidgetItem* item=new QListWidgetItem();
//    listWidget->setItemWidget(item,lineEdit);
//    return listWidget;
//}




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
//    ActivityList list("name1","addTime1",12);
//    ActivityListDao::saveActivityList(list);
    //QListWidget* listWidget = initListWidget();
    //QListView* listView=initListView();

    //最外面的水平大的布局
    QVBoxLayout* vBoxLayout=new QVBoxLayout;

    //LoadActivityListDataThread loadDataThread;
    //loadDataThread.start();
    //connect(&loadDataThread,SIGNAL(dataLoaded()),this,SLOT(updateList()));

    LoadActivityListData* service=new LoadActivityListData;
    service->moveToThread(&mLoadDataThread);

    connect(&mLoadDataThread,&QThread::finished,service,&QObject::deleteLater);
    connect(this, &TaskView::startLoadData, service, &LoadActivityListData::loadData);
    connect(service, &LoadActivityListData::dataLoaded, this, &TaskView::updateList);
    mLoadDataThread.start();

    startLoadData();
    initScrollArea();



    //水平的按钮
    QHBoxLayout* hBoxLayout=new QHBoxLayout;
    QPushButton* confirmBtn=new QPushButton("确定");
    QPushButton* addBtn=new QPushButton("添加");
    connect(addBtn,SIGNAL(clicked(bool)),this,SLOT(createAddTaskDialog()));
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(addBtn);
    hBoxLayout->addWidget(confirmBtn);
    hBoxLayout->addStretch();

    vBoxLayout->addWidget(mScrollArea);
    vBoxLayout->addStretch();
    vBoxLayout->addLayout(hBoxLayout);
    this->setLayout(vBoxLayout);
}

TaskView::~TaskView()
{
    mLoadDataThread.quit();
    mLoadDataThread.wait();
}

void TaskView::initScrollArea()
{
    mScrollArea=new QScrollArea();
    mScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void TaskView::initListLayout()
{
    mCustomListLayout=new CustomListLayout(mScrollArea);
    //QLayout::SetMinAndMaxSize	5	The main widget's minimum size is set to minimumSize() and
    //its maximum size is set to maximumSize().
    mCustomListLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    foreach (ActivityList* activity, mActivityLists) {
        TaskItemWidget* taskItem=new TaskItemWidget;
        taskItem->setTaskName(activity->getActivityName());
        mCustomListLayout->append(taskItem);
    }
    mActivityListWidget=new QWidget;
    mActivityListWidget->setLayout(mCustomListLayout);
    mScrollArea->setWidget(mActivityListWidget);
}

void TaskView::createAddTaskDialog()
{
    qDebug()<<"create add task dialog";
    AddTaskDialog* mAddTaskDialog=new AddTaskDialog(this);
    mAddTaskDialog->show();
}

void TaskView::updateList(QList<ActivityList*> lists)
{
    qDebug()<<"update view";
    //initListLayout();
}






