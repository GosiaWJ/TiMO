#-------------------------------------------------
#
# Project created by QtCreator 2018-04-12T13:16:46
#
#-------------------------------------------------

QT       += core gui widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = optymalizacje
TEMPLATE = app

OBJECTS_DIR=./obj
INCLUDEPATH=inc
INCLUDEPATH+=ui/inc
INCLUDEPATH+=.inc
INCLUDEPATH+=.inc/qcustomplot
INCLUDEPATH+=./ui/inc
TRANSLATIONS=langs/diagui_en.ts
MOC_DIR=./out/moc
RCC_DIR=./out/rcc
UI_DIR=./out/uic
QMAKE_CXXFLAGS+=-std=c++11
MOC_DIR=./out/moc
TEMPLATE = app
TARGET = OPTYMALIZACJA
DEPENDPATH += ui \
              src \
              inc/qcustomplot \
              inc \
              src/qcustomplot \

INCLUDEPATH += . inc inc/qcustomplot

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/qcustomplot/qcustomplot.cpp \
    src/wykres.cpp \
    src/dane.cpp

HEADERS  += inc/qcustomplot/qcustomplot.h \
    inc/mainwindow.hh \
    inc/wykres.hh \
    inc/dane.hh

FORMS    += mainwindow.ui
