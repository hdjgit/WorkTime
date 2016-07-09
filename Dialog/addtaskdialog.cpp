#include "addtaskdialog.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QApplication>
#include "Dao/activitylistdao.h"
#include "Domain/activitylist.h"
#include "Util/timeutil.h"

AddTaskDialog::AddTaskDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("添加任务");
    QGridLayout* gridLayout=new QGridLayout;
    QLabel* nameLabel=new QLabel("任务名：");

    mNameEdit=new QLineEdit;
    gridLayout->addWidget(nameLabel,0,0);
    gridLayout->addWidget(mNameEdit,0,1);

    QVBoxLayout* vBoxLayout=new QVBoxLayout;

    //水平的按钮
    QHBoxLayout* hBoxLayout=new QHBoxLayout;
    QPushButton* confirmBtn=new QPushButton("确定");
    connect(confirmBtn,SIGNAL(clicked(bool)),this,SLOT(addTaskToDb()));

    //确定按钮得到焦点
    confirmBtn->setDefault(true);
    QPushButton* cancelBtn=new QPushButton("取消");
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(cancelBtn);
    hBoxLayout->addWidget(confirmBtn);
    hBoxLayout->addStretch();

    vBoxLayout->addLayout(gridLayout);
    vBoxLayout->addLayout(hBoxLayout);

    this->setLayout(vBoxLayout);
}

void AddTaskDialog::addTaskToDb()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //qDebug()<<"add task to db";
    ActivityList activityList(mNameEdit->text(),TimeUtil::getCurrentTime(),0);
    ActivityListDao().saveActivityList(activityList);
    QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
    QApplication::restoreOverrideCursor();
    this->close();
}
