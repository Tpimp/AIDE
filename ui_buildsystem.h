/********************************************************************************
** Form generated from reading UI file 'buildsystem.ui'
**
** Created: Thu Dec 20 19:47:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDSYSTEM_H
#define UI_BUILDSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuildSystem
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BuildSystem)
    {
        if (BuildSystem->objectName().isEmpty())
            BuildSystem->setObjectName(QString::fromUtf8("BuildSystem"));
        BuildSystem->resize(571, 435);
        centralWidget = new QWidget(BuildSystem);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        BuildSystem->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BuildSystem);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 571, 25));
        BuildSystem->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BuildSystem);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BuildSystem->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BuildSystem);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BuildSystem->setStatusBar(statusBar);

        retranslateUi(BuildSystem);

        QMetaObject::connectSlotsByName(BuildSystem);
    } // setupUi

    void retranslateUi(QMainWindow *BuildSystem)
    {
        BuildSystem->setWindowTitle(QApplication::translate("BuildSystem", "BuildSystem", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BuildSystem: public Ui_BuildSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDSYSTEM_H
