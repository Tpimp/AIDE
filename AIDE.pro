#-------------------------------------------------
#
# Project created by QtCreator 2012-12-02T01:21:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AIDE
TEMPLATE = app


SOURCES += main.cpp\
        aide.cpp \
    newfiledialog.cpp\
    projectexplorer.cpp \
    projectfile.cpp \
    editor.cpp

HEADERS  += aide.h \
    newfiledialog.h \
    projectexplorer.h \
    projectfile.h \
    editor.h

FORMS    += aide.ui \
    newfiledialog.ui \
    projectexplorer.ui \
    editor.ui


RESOURCES += \
    aide_resource.qrc
