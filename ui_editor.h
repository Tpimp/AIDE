/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created: Sun Dec 23 11:49:08 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *TabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTextEdit *TextEdit;
    QWidget *tab_2;

    void setupUi(QWidget *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QString::fromUtf8("Editor"));
        Editor->resize(1059, 809);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Editor->sizePolicy().hasHeightForWidth());
        Editor->setSizePolicy(sizePolicy);
        Editor->setMinimumSize(QSize(10, 10));
        gridLayout = new QGridLayout(Editor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TabWidget = new QTabWidget(Editor);
        TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        TextEdit = new QTextEdit(tab);
        TextEdit->setObjectName(QString::fromUtf8("TextEdit"));

        gridLayout_2->addWidget(TextEdit, 0, 0, 1, 1);

        TabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        TabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(TabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Editor);

        TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QWidget *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "Form", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab), QApplication::translate("Editor", "Tab 1", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab_2), QApplication::translate("Editor", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
