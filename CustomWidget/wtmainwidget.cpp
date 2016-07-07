#include "wtmainwidget.h"
#include <QTabWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "UI/clockview.h"
#include "UI/taskview.h"

void WTMainWidget::initTab()
{
    mClockView=new ClockView;
    mTabWidget->addTab(mClockView, "时间");

    mTaskView=new TaskView();
    mTabWidget->addTab(mTaskView, "任务");

    //向QTabWidget中添加第三个页面
    QPushButton *pushButton3 = new QPushButton("Click Me");
    mTabWidget->addTab(pushButton3, "设置");
}

WTMainWidget::WTMainWidget(QWidget *parent) : QWidget(parent)
{
    mTabWidget=new QTabWidget;

    initTab();

    QLineEdit* inputLineEdit=new QLineEdit();
    //自定义控件背景还是很奇怪
    //inputLineEdit->setStyleSheet("border-image:url(:/img/textfield.png);"
                                 //"height:50px;");
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(inputLineEdit);
    layout->addWidget(mTabWidget);

    this->setLayout(layout);
    this->resize(300, 100);
    this->setWindowTitle("QTabWidgetDemo");

}

QSize WTMainWidget::sizeHint() const
{
    return QSize(375,375);
}
