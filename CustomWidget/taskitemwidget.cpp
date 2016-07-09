#include "taskitemwidget.h"
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
void TaskItemWidget::initCheckBox()
{
    mCheckBox=new QCheckBox;
    mCheckBox->setStyleSheet("QCheckBox::indicator:checked"
                             "{"
                             "image: url(:/img/checkbox_checked.png);"

                             "border-image:url(:/img/checkbox.png) 0 0 0 0 stretch stretch;"
                             "}"
                             "QCheckBox::indicator {"
                             "image: url(:/img/checkbox.png);"
                             "width:18px;"
                             "height:18px;"
                             "}");
}

void TaskItemWidget::setTaskName(QString taskName)
{
    mTaskName->setText(taskName);
}

TaskItemWidget::TaskItemWidget(QWidget *parent) : QWidget(parent)
{
    initCheckBox();

    mTaskName=new QLabel;

    QHBoxLayout* hBoxLayout=new QHBoxLayout;
    hBoxLayout->addWidget(mCheckBox);
    hBoxLayout->addWidget(mTaskName);
    this->setLayout(hBoxLayout);
}
