#-------------------------------------------------
#
# Project created by QtCreator 2018-02-11T18:03:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = awesomeCalc
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    button.cpp \
    buttonfactory.cpp \
    multiplybutton.cpp \
    dividebutton.cpp \
    dotbutton.cpp \
    deletebutton.cpp \
    buffer.cpp \
    operatorbutton.cpp \
    digitbutton.cpp \
    equalbutton.cpp

HEADERS  += mainwindow.h \
    button.h \
    buttonfactory.h \
    multiplybutton.h \
    dividebutton.h \
    dotbutton.h \
    deletebutton.h \
    buffer.h \
    operatorbutton.h \
    digitbutton.h \
    equalbutton.h

FORMS    += mainwindow.ui

DISTFILES +=
