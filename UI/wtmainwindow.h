#ifndef WTMAINWINDOW_H
#define WTMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

class CalcTimeWidget;
class QGridLayout;
class QVBoxLayout;

class WTMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit WTMainWindow(QWidget *parent = 0);

    void initMainWindowColor();

signals:

public slots:
private:
    CalcTimeWidget* mCalcTimeWidget;
    //QGridLayout* mGridLayout;
    QVBoxLayout* mVBoxLayout;
    QLabel* mTopic;
};

#endif // WTMAINWINDOW_H
