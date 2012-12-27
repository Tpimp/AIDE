/********************************************************************************
** Form generated from reading UI file 'aide.ui'
**
** Created: Tue Dec 25 16:55:52 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDE_H
#define UI_AIDE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Aide
{
public:
    QAction *ActionExit;
    QAction *ActionNew;
    QAction *ActionBuild_and_Run;
    QAction *ActionBuild_and_Debug;
    QAction *ActionClean;
    QAction *ActionReBuild;
    QAction *ActionProject;
    QAction *ActionAllFiles;
    QAction *ActionCurrentFile;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *MenuAIDE;
    QMenu *menuSave;
    QMenu *MenuEDIT;
    QMenu *MenuVIEW;
    QMenu *MenuWINDOW;
    QMenu *MenuABOUT;
    QMenu *menuPROJECT;
    QToolBar *ToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Aide)
    {
        if (Aide->objectName().isEmpty())
            Aide->setObjectName(QString::fromUtf8("Aide"));
        Aide->resize(894, 577);
        QFont font;
        font.setFamily(QString::fromUtf8("Baskerville Old Face"));
        font.setPointSize(12);
        Aide->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/AIDE_Icon_small.png"), QSize(), QIcon::Normal, QIcon::Off);
        Aide->setWindowIcon(icon);
        ActionExit = new QAction(Aide);
        ActionExit->setObjectName(QString::fromUtf8("ActionExit"));
        ActionNew = new QAction(Aide);
        ActionNew->setObjectName(QString::fromUtf8("ActionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/new_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionNew->setIcon(icon1);
        ActionBuild_and_Run = new QAction(Aide);
        ActionBuild_and_Run->setObjectName(QString::fromUtf8("ActionBuild_and_Run"));
        ActionBuild_and_Debug = new QAction(Aide);
        ActionBuild_and_Debug->setObjectName(QString::fromUtf8("ActionBuild_and_Debug"));
        ActionClean = new QAction(Aide);
        ActionClean->setObjectName(QString::fromUtf8("ActionClean"));
        ActionReBuild = new QAction(Aide);
        ActionReBuild->setObjectName(QString::fromUtf8("ActionReBuild"));
        ActionProject = new QAction(Aide);
        ActionProject->setObjectName(QString::fromUtf8("ActionProject"));
        ActionAllFiles = new QAction(Aide);
        ActionAllFiles->setObjectName(QString::fromUtf8("ActionAllFiles"));
        ActionCurrentFile = new QAction(Aide);
        ActionCurrentFile->setObjectName(QString::fromUtf8("ActionCurrentFile"));
        centralWidget = new QWidget(Aide);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Aide->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Aide);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 894, 27));
        menuBar->setNativeMenuBar(false);
        MenuAIDE = new QMenu(menuBar);
        MenuAIDE->setObjectName(QString::fromUtf8("MenuAIDE"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/AIDE_Button_Small.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuAIDE->setIcon(icon2);
        menuSave = new QMenu(MenuAIDE);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        MenuEDIT = new QMenu(menuBar);
        MenuEDIT->setObjectName(QString::fromUtf8("MenuEDIT"));
        MenuVIEW = new QMenu(menuBar);
        MenuVIEW->setObjectName(QString::fromUtf8("MenuVIEW"));
        MenuWINDOW = new QMenu(menuBar);
        MenuWINDOW->setObjectName(QString::fromUtf8("MenuWINDOW"));
        MenuABOUT = new QMenu(menuBar);
        MenuABOUT->setObjectName(QString::fromUtf8("MenuABOUT"));
        menuPROJECT = new QMenu(menuBar);
        menuPROJECT->setObjectName(QString::fromUtf8("menuPROJECT"));
        Aide->setMenuBar(menuBar);
        ToolBar = new QToolBar(Aide);
        ToolBar->setObjectName(QString::fromUtf8("ToolBar"));
        ToolBar->setIconSize(QSize(30, 30));
        ToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        Aide->addToolBar(Qt::TopToolBarArea, ToolBar);
        statusBar = new QStatusBar(Aide);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Aide->setStatusBar(statusBar);

        menuBar->addAction(MenuAIDE->menuAction());
        menuBar->addAction(menuPROJECT->menuAction());
        menuBar->addAction(MenuEDIT->menuAction());
        menuBar->addAction(MenuVIEW->menuAction());
        menuBar->addAction(MenuWINDOW->menuAction());
        menuBar->addAction(MenuABOUT->menuAction());
        MenuAIDE->addAction(ActionNew);
        MenuAIDE->addAction(menuSave->menuAction());
        MenuAIDE->addAction(ActionExit);
        menuSave->addAction(ActionProject);
        menuSave->addAction(ActionAllFiles);
        menuSave->addAction(ActionCurrentFile);
        menuPROJECT->addAction(ActionBuild_and_Run);
        menuPROJECT->addAction(ActionBuild_and_Debug);
        menuPROJECT->addAction(ActionClean);
        menuPROJECT->addAction(ActionReBuild);
        ToolBar->addAction(ActionNew);

        retranslateUi(Aide);

        QMetaObject::connectSlotsByName(Aide);
    } // setupUi

    void retranslateUi(QMainWindow *Aide)
    {
        Aide->setWindowTitle(QApplication::translate("Aide", "Aide", 0, QApplication::UnicodeUTF8));
        ActionExit->setText(QApplication::translate("Aide", "Exit", 0, QApplication::UnicodeUTF8));
        ActionNew->setText(QApplication::translate("Aide", "New File or Project", 0, QApplication::UnicodeUTF8));
        ActionBuild_and_Run->setText(QApplication::translate("Aide", "Build and Run", 0, QApplication::UnicodeUTF8));
        ActionBuild_and_Run->setShortcut(QApplication::translate("Aide", "F5", 0, QApplication::UnicodeUTF8));
        ActionBuild_and_Debug->setText(QApplication::translate("Aide", "Build and Debug", 0, QApplication::UnicodeUTF8));
        ActionBuild_and_Debug->setShortcut(QApplication::translate("Aide", "Shift+F5", 0, QApplication::UnicodeUTF8));
        ActionClean->setText(QApplication::translate("Aide", "Clean", 0, QApplication::UnicodeUTF8));
        ActionReBuild->setText(QApplication::translate("Aide", "ReBuild", 0, QApplication::UnicodeUTF8));
        ActionProject->setText(QApplication::translate("Aide", "Project", 0, QApplication::UnicodeUTF8));
        ActionAllFiles->setText(QApplication::translate("Aide", "All Files", 0, QApplication::UnicodeUTF8));
        ActionCurrentFile->setText(QApplication::translate("Aide", "Current File", 0, QApplication::UnicodeUTF8));
        MenuAIDE->setTitle(QString());
        menuSave->setTitle(QApplication::translate("Aide", "Save", 0, QApplication::UnicodeUTF8));
        MenuEDIT->setTitle(QApplication::translate("Aide", "EDIT", 0, QApplication::UnicodeUTF8));
        MenuVIEW->setTitle(QApplication::translate("Aide", "VIEW", 0, QApplication::UnicodeUTF8));
        MenuWINDOW->setTitle(QApplication::translate("Aide", "WINDOW", 0, QApplication::UnicodeUTF8));
        MenuABOUT->setTitle(QApplication::translate("Aide", "ABOUT", 0, QApplication::UnicodeUTF8));
        menuPROJECT->setTitle(QApplication::translate("Aide", "PROJECT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Aide: public Ui_Aide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDE_H
