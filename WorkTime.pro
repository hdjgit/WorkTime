FORMS +=

HEADERS += \
    CustomWidget/calctimewidget.h \
    UI/wtmainwindow.h \
    CustomWidget/wtmainwidget.h \
    UI/clockview.h \
    UI/taskview.h \
    Domain/activitylist.h \
    Util/dbutil.h \
    Dao/activitylistdao.h

SOURCES += \
    CustomWidget/calctimewidget.cpp \
    main.cpp \
    UI/wtmainwindow.cpp \
    CustomWidget/wtmainwidget.cpp \
    UI/clockview.cpp \
    UI/taskview.cpp \
    Domain/activitylist.cpp \
    Util/dbutil.cpp \
    Dao/activitylistdao.cpp

QT+=widgets gui sql

DISTFILES +=

RESOURCES += \
    resource.qrc
