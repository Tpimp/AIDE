/********************************************************************************
** Form generated from reading UI file 'projectexplorer.ui'
**
** Created: Tue Dec 25 11:38:57 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTEXPLORER_H
#define UI_PROJECTEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectExplorer
{
public:
    QWidget *DockWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *VerticalLayout;
    QComboBox *ProjectSelector;
    QTreeWidget *TreeWidget;

    void setupUi(QDockWidget *ProjectExplorer)
    {
        if (ProjectExplorer->objectName().isEmpty())
            ProjectExplorer->setObjectName(QString::fromUtf8("ProjectExplorer"));
        ProjectExplorer->resize(327, 709);
        ProjectExplorer->setStyleSheet(QString::fromUtf8("QDockWidget{ border: 2px solid black;}"));
        DockWidgetContents = new QWidget();
        DockWidgetContents->setObjectName(QString::fromUtf8("DockWidgetContents"));
        gridLayout = new QGridLayout(DockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        VerticalLayout = new QVBoxLayout();
        VerticalLayout->setSpacing(2);
        VerticalLayout->setObjectName(QString::fromUtf8("VerticalLayout"));
        ProjectSelector = new QComboBox(DockWidgetContents);
        ProjectSelector->setObjectName(QString::fromUtf8("ProjectSelector"));

        VerticalLayout->addWidget(ProjectSelector);

        TreeWidget = new QTreeWidget(DockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        TreeWidget->setHeaderItem(__qtreewidgetitem);
        TreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        TreeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        TreeWidget->setAlternatingRowColors(true);
        TreeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        TreeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        TreeWidget->setIconSize(QSize(18, 18));
        TreeWidget->setHeaderHidden(true);

        VerticalLayout->addWidget(TreeWidget);


        gridLayout->addLayout(VerticalLayout, 1, 0, 1, 1);

        ProjectExplorer->setWidget(DockWidgetContents);

        retranslateUi(ProjectExplorer);

        QMetaObject::connectSlotsByName(ProjectExplorer);
    } // setupUi

    void retranslateUi(QDockWidget *ProjectExplorer)
    {
        ProjectExplorer->setWindowTitle(QApplication::translate("ProjectExplorer", "DockWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProjectExplorer: public Ui_ProjectExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTEXPLORER_H
