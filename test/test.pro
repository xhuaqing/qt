#-------------------------------------------------
#
# Project created by QtCreator 2013-03-30T10:29:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cc\
        mainwindow.cc \
    eventlabel.cc \
    paintedwidget.cc

HEADERS  += mainwindow.h \
    eventlabel.h \
    paintedwidget.h

RESOURCES += \
    test.qrc

QMAKE_CXXFLAGS += -std=c++11
