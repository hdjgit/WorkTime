#include "clockview.h"
#include <QTabWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

ClockView::ClockView(QWidget *parent) : QWidget(parent)
{
    QLineEdit *lineEdit = new QLineEdit();
    QPushButton *pushButton = new QPushButton("Test");
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(lineEdit);
    vLayout->addWidget(pushButton);
    this->setLayout(vLayout);
    //setVisible(false);
}
