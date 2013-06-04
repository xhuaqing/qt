#-------------------------------------------------
#
# Project created by QtCreator 2013-05-28T16:05:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stu
TEMPLATE = app


SOURCES += main.cpp \
    finddialog.cpp \
    gotocelldialog.cpp \
    sortdialog.cpp \
    mainwindow.cpp

HEADERS  += \
    finddialog.h \
    gotocelldialog.h \
    sortdialog.h \
    mainwindow.h

CONFIG += c++11

FORMS += \
    gotocelldialog.ui \
    sortdialog.ui

RESOURCES += \
    stu.qrc

OTHER_FILES +=
