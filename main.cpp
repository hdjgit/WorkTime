#include <QApplication>
#include "CustomWidget/calctimewidget.h"
#include "UI/wtmainwindow.h"

int main(int argc,char* argv[]){
    QApplication app(argc,argv);
//    CalcTimeWidget widget;
//    widget.show();
    WTMainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
