#include "taskitemwidget.h"
#include <QCheckBox>
#include <QHBoxLayout>
TaskItemWidget::TaskItemWidget(QWidget *parent) : QWidget(parent)
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
    QHBoxLayout* hBoxLayout=new QHBoxLayout;
    hBoxLayout->addWidget(mCheckBox);
    this->setLayout(hBoxLayout);
}
