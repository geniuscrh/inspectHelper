#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T17:18:14
#
#-------------------------------------------------

QT       += core gui
QT += network
QT +=  axcontainer


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = inspectHelper
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    NetworkCookieJar.cpp \
    TableViewService.cpp \
    SiteObject.cpp \
    ThreadMsg.cpp \
    AutoThread.cpp

HEADERS  += MainWindow.h \
    NetworkCookieJar.h \
    TableViewService.h \
    SiteObject.h \
    ThreadMsg.h \
    AutoThread.h

FORMS    += MainWindow.ui
