#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T10:46:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Memory+
TEMPLATE = app

CONFIG += c++14

QMAKE_CXXFLAGS += -std=c++14

DSG = /home/angel/Escritorio/DeSiGNAR/

INCLUDEPATH += $${DSG}/include ../

LIBS += -L$${DSG}/lib -lDesignar

SOURCES += source/main.cpp\
        source/mainwindow.cpp \
    source/about.cpp \
    source/game_select.cpp \
    source/game_c.cpp \
    source/button.cpp \
    source/game_r.cpp \
    source/aux_functions.cpp

HEADERS  += headers/mainwindow.h \
    headers/game_select.h \
    headers/about.h \
    headers/Card.h \
    headers/game_c.h \
    headers/button.h \
    headers/game_r.h \
    headers/aux_functions.h

FORMS    += ui/mainwindow.ui \
    ui/game_select.ui \
    ui/about.ui

RESOURCES += \
    rsrc.qrc
