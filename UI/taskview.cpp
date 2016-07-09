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


    initListLayout();

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

void TaskView::initScrollArea()
{
    mScrollArea=new QScrollArea();
    mScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mScrollArea->setWidget(mActivityListWidget);
}

void TaskView::initListLayout()
{
    mCustomListLayout=new CustomListLayout(mScrollArea);
    //QLayout::SetMinAndMaxSize	5	The main widget's minimum size is set to minimumSize() and
    //its maximum size is set to maximumSize().
    mCustomListLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    //listLayout->SetFixedSize
    TaskItemWidget* taskItem1=new TaskItemWidget;
    taskItem1->setTaskName("这是第一个任务");
    QLabel* edit2=new QLabel("text2");
    QLabel* edit3=new QLabel("text3");
    QLabel* edit4=new QLabel("text4");
    QLabel* edit5=new QLabel("text5");
    QLabel* edit6=new QLabel("text6");
    QLabel* edit7=new QLabel("text7");
    QLabel* edit8=new QLabel("text8");
    QLabel* edit9=new QLabel("text9");
    QLabel* edit15=new QLabel("text15");
    QLabel* edit16=new QLabel("text16");
    QLabel* edit17=new QLabel("text17");
    QLabel* edit18=new QLabel("text18");
    QLabel* edit19=new QLabel("text19");
    QLabel* edit115=new QLabel("text115");
    QLabel* edit116=new QLabel("text116");
    QLabel* edit117=new QLabel("text117");
    QLabel* edit118=new QLabel("text118");
    QLabel* edit119=new QLabel("text119");
    mCustomListLayout->append(taskItem1);
    mCustomListLayout->append(edit2);
    mCustomListLayout->append(edit3);
    mCustomListLayout->append(edit4);
    mCustomListLayout->append(edit5);
    mCustomListLayout->append(edit6);
    mCustomListLayout->append(edit7);
    mCustomListLayout->append(edit8);
    mCustomListLayout->append(edit9);
    mCustomListLayout->append(edit15);
    mCustomListLayout->append(edit16);
    mCustomListLayout->append(edit17);
    mCustomListLayout->append(edit18);
    mCustomListLayout->append(edit19);
    mCustomListLayout->append(edit115);
    mCustomListLayout->append(edit116);
    mCustomListLayout->append(edit117);
    mCustomListLayout->append(edit118);
    mCustomListLayout->append(edit119);

    mActivityListWidget=new QWidget;
    mActivityListWidget->setLayout(mCustomListLayout);
}

void TaskView::createAddTaskDialog()
{
    qDebug()<<"create add task dialog";
    AddTaskDialog* mAddTaskDialog=new AddTaskDialog(this);
    mAddTaskDialog->show();
}


