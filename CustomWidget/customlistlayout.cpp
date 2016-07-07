#include "customlistlayout.h"
#include <QWidget>

CustomListLayout::CustomListLayout(QWidget *parent) : QVBoxLayout(parent)
{
    mWidgetList=new QList<QWidget*>();

}

CustomListLayout::~CustomListLayout()
{
    mWidgetList->clear();
    delete mWidgetList;
    mWidgetList=0;
}

void CustomListLayout::append(QWidget *widget)
{
    mWidgetList->append(widget);
    addWidget(widget);
}

//QSize CustomListLayout::sizeHint()
//{
//    return QSize(-1,200);
//}

//QSize CustomListLayout::maximumSize()
//{
//    return QSize(200,300);
//}




