#include <QApplication>
#include "CustomWidget/calctimewidget.h"

int main(int argc,char* argv[]){
    QApplication app(argc,argv);
    CalcTimeWidget widget;
    widget.show();
    return app.exec();
}
