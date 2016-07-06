#include "wtmainwindow.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "CustomWidget/calctimewidget.h"
#include "CustomWidget/wtmainwidget.h"


void WTMainWindow::initMainWindowBgColor()
{
    QPalette palette;
    //QBrush bgBrush;
    //bgBrush.setColor(QColor(255,255,255));
    palette.setColor(backgroundRole(), QColor(255,255,255));

    setPalette(palette);
}

WTMainWindow::WTMainWindow(QWidget *parent) : QMainWindow(parent)
{
    //    //mGridLayout=new QGridLayout(this);
    //mCalcTimeWidget=new CalcTimeWidget;
    //    //mGridLayout->addWidget(mCalcTimeWidget);

    //    //setLayout(mGridLayout);
    //mVBoxLayout=new QVBoxLayout();
    //mTopic=new QLabel("haha");
    //    mVBoxLayout->addWidget(mCalcTimeWidget);
    //mVBoxLayout->addWidget(mTopic);
    //setLayout(mVBoxLayout);
    mMainWidget=new WTMainWidget;
    setCentralWidget(mMainWidget);
    //固定窗口大小
    setFixedSize(375,375);
    initMainWindowBgColor();
}
