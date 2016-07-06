#include "wtmainwidget.h"
#include <QTabWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "UI/clockview.h"

WTMainWidget::WTMainWidget(QWidget *parent) : QWidget(parent)
{
    mTabWidget=new QTabWidget;

    mClockView=new ClockView;

    //新建第二个页面的部件
    QLabel *label = new QLabel("Hello Qt");

    //新建第三个页面的部件
    QPushButton *pushButton3 = new QPushButton("Click Me");

    //向QTabWidget中添加第一个页面
    //QIcon icon1(":/img/clock.png");

    mTabWidget->addTab(mClockView, "时间");
    //mTabWidget->setIconSize(QSize(30,30));

    //向QTabWidget中添加第二个页面
    QIcon icon2(":/new/icon/images/2.ico");
    mTabWidget->addTab(label, icon2, "Tab2");

    //向QTabWidget中添加第三个页面
    QIcon icon3(":/new/icon/images/3.ico");
    mTabWidget->addTab(pushButton3, icon3, "Tab3");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(mTabWidget);

    this->setLayout(layout);
    this->resize(300, 100);
    this->setWindowTitle("QTabWidgetDemo");

}

QSize WTMainWidget::sizeHint() const
{
    return QSize(375,375);
}
