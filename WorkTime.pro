FORMS +=

HEADERS += \
    CustomWidget/calctimewidget.h \
    UI/wtmainwindow.h \
    CustomWidget/wtmainwidget.h \
    UI/clockview.h \
    UI/taskview.h \
    Domain/activitylist.h \
    Util/dbutil.h \
    Dao/activitylistdao.h \
    CustomWidget/customlistlayout.h \
    CustomWidget/taskitemwidget.h \
    Dialog/addtaskdialog.h \
    Util/timeutil.h

SOURCES += \
    CustomWidget/calctimewidget.cpp \
    main.cpp \
    UI/wtmainwindow.cpp \
    CustomWidget/wtmainwidget.cpp \
    UI/clockview.cpp \
    UI/taskview.cpp \
    Domain/activitylist.cpp \
    Util/dbutil.cpp \
    Dao/activitylistdao.cpp \
    CustomWidget/customlistlayout.cpp \
    CustomWidget/taskitemwidget.cpp \
    Dialog/addtaskdialog.cpp \
    Util/timeutil.cpp

QT+=widgets gui sql

DISTFILES +=

RESOURCES += \
    resource.qrc
