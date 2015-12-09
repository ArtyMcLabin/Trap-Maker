#-------------------------------------------------
#
# Project created by QtCreator 2015-12-06T20:22:48
#
#-------------------------------------------------

QT       += core gui multimedia
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trap-Maker2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    looped.cpp

HEADERS  += widget.h \
    looped.h \
    personal_macros.h

FORMS    += widget.ui

RESOURCES += \
    rs.qrc
