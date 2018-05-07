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
INCLUDEPATH+=.inc/muparser
INCLUDEPATH+=.inc/diff
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
    src/dane.cpp \
    src/muparser/muParser.cpp \
    src/muparser/muParserBase.cpp \
    src/muparser/muParserBytecode.cpp \
    src/muparser/muParserCallback.cpp \
    src/muparser/muParserDLL.cpp \
    src/muparser/muParserError.cpp \
    src/muparser/muParserInt.cpp \
    src/muparser/muParserTest.cpp \
    src/muparser/muParserTokenReader.cpp \
    inc/diff/expression.cxx \
    inc/diff/operand.cxx \
    inc/diff/parser.cxx

HEADERS  += inc/qcustomplot/qcustomplot.h \
    inc/mainwindow.hh \
    inc/wykres.hh \
    inc/dane.hh \
    inc/muparser/muParser.h \
    inc/muparser/muParserBase.h \
    inc/muparser/muParserBytecode.h \
    inc/muparser/muParserCallback.h \
    inc/muparser/muParserDef.h \
    inc/muparser/muParserDLL.h \
    inc/muparser/muParserError.h \
    inc/muparser/muParserFixes.h \
    inc/muparser/muParserInt.h \
    inc/muparser/muParserStack.h \
    inc/muparser/muParserTemplateMagic.h \
    inc/muparser/muParserTest.h \
    inc/muparser/muParserToken.h \
    inc/muparser/muParserTokenReader.h \
    inc/diff/auxiliary.h \
    inc/diff/common.h \
    inc/diff/exceptions.h \
    inc/diff/expression.h \
    inc/diff/operand.h \
    inc/diff/parser.h \
    inc/diff/tree.h

FORMS    += mainwindow.ui
