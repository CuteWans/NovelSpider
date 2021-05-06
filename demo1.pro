QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fail_to_act.cpp \
    fail_to_getpage.cpp \
    filedownloader.cpp \
    find_page.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    fail_to_act.h \
    fail_to_getpage.h \
    filedownloader.h \
    find_page.h \
    mainwindow.h

FORMS += \
    fail_to_act.ui \
    fail_to_getpage.ui \
    find_page.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
