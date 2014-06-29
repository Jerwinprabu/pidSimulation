#-------------------------------------------------
#
# Project created by QtCreator 2014-06-28T17:04:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sim.cpp \
    guihandler.cpp

HEADERS  += mainwindow.h \
    sim.h \
    guihandler.h

FORMS    += mainwindow.ui

LIBS+=-L/usr/lib /usr/lib/libkdeui.so

QMAKE_CXXFLAGS += -std=c++11
