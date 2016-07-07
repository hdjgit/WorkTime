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

    QScrollArea* area=new QScrollArea();

    //area->setSizePolicy();
    area->setWidgetResizable(false);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    CustomListLayout* listLayout=new CustomListLayout(area);
    //QLayout::SetMinAndMaxSize	5	The main widget's minimum size is set to minimumSize() and
    //its maximum size is set to maximumSize().
    listLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    //listLayout->SetFixedSize
    QLabel* edit1=new QLabel("text1");
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
    listLayout->append(edit1);
    listLayout->append(edit2);
    listLayout->append(edit3);
    listLayout->append(edit4);
    listLayout->append(edit5);
    listLayout->append(edit6);
    listLayout->append(edit7);
    listLayout->append(edit8);
    listLayout->append(edit9);
    listLayout->append(edit15);
    listLayout->append(edit16);
    listLayout->append(edit17);
    listLayout->append(edit18);
    listLayout->append(edit19);
    listLayout->append(edit115);
    listLayout->append(edit116);
    listLayout->append(edit117);
    listLayout->append(edit118);
    listLayout->append(edit119);
    area->setMaximumHeight(400);

    //area->widget()->setLayout(listLayout);
    QWidget* widget=new QWidget;
    widget->setLayout(listLayout);
    area->setWidget(widget);

    //水平的按钮
    QHBoxLayout* hBoxLayout=new QHBoxLayout;
    QPushButton* confirmBtn=new QPushButton("确定");
    hBoxLayout->addWidget(confirmBtn);

    vBoxLayout->addWidget(area);
    vBoxLayout->addStretch();
    vBoxLayout->addLayout(hBoxLayout);
    this->setLayout(vBoxLayout);
}


