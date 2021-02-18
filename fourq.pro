QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/api/sql/sqlitedao.cpp \
    src/api/sql/sqlitewrapper.cpp \
    src/dialogs/searchdialog.cpp \
    src/infowidget.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/widgets/fourqwidget.cpp \
    src/widgets/fourqwidgetitem.cpp \
    src/widgets/usericonwidget.cpp

HEADERS += \
    src/api/sql/sqlitedao.h \
    src/api/sql/sqlitewrapper.h \
    src/dialogs/searchdialog.h \
    src/infowidget.h \
    src/mainwindow.h \
    src/widgets/fourqwidget.h \
    src/widgets/fourqwidgetitem.h \
    src/widgets/usericonwidget.h

FORMS += \
    src/dialogs/searchdialog.ui \
    src/infowidget.ui \
    src/mainwindow.ui \
    src/widgets/fourqwidget.ui \
    src/widgets/usericonwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR=$$PWD/bin/
RC_ICONS=app.ico

RESOURCES += \
    app.qrc
