#ifndef CUSTOMLISTLAYOUT_H
#define CUSTOMLISTLAYOUT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QList>
/*
 * listView文档太少了，找了半天还是自己写一个吧
 * 用来从上至下放置ActivityList数据，或者其他数据
 */
class CustomListLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit CustomListLayout(QWidget *parent = 0);
    ~CustomListLayout();
    void append(QWidget* widget);
    //QSize maximumSize();
    //QSize sizeHint();
signals:

public slots:
private:
    QList<QWidget*>* mWidgetList;
};

#endif // CUSTOMLISTLAYOUT_H
