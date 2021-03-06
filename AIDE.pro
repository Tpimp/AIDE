#-------------------------------------------------
#
# Project created by QtCreator 2012-12-02T01:21:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AIDE.exe
TEMPLATE = app


SOURCES += main.cpp\
        aide.cpp \
    projectexplorer.cpp \
    projectfile.cpp \
    editor.cpp \
    newdialog.cpp\
    syntaxfile.cpp \
    highlighter.cpp


HEADERS  += aide.h \
    projectexplorer.h \
    projectfile.h \
    editor.h \
    file_info.h \
    newdialog.h \
    syntaxfile.h \
    syntaxpattern.h \
    highlighter.h \
    keywordlist.h


FORMS    += aide.ui \
    projectexplorer.ui \
    editor.ui \
    newdialog.ui


RESOURCES += \
    aide_resource.qrc

OTHER_FILES += \
    data/startup/known_types.conf \
    Developer_Notes_and_Practices.nfo \
    images/files/cpp.png \
    images/files/asm.png
