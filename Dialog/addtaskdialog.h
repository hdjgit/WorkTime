#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QWidget>
#include <QDialog>
class QLineEdit;
class AddTaskDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddTaskDialog(QWidget *parent = 0);

signals:

public slots:
    void addTaskToDb();
private:
    QLineEdit* mNameEdit;
};

#endif // ADDTASKDIALOG_H
