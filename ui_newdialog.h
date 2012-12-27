/********************************************************************************
** Form generated from reading UI file 'newdialog.ui'
**
** Created: Sun Dec 23 11:49:08 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIALOG_H
#define UI_NEWDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDialog
{
public:
    QStackedWidget *StackedWidget;
    QWidget *page;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *NewItemLayout;
    QTreeWidget *ProjectTree;
    QTreeWidget *FileTree;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ExtensionLabel;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QFrame *ExtensionFrame;
    QLineEdit *ExtensionEdit;
    QHBoxLayout *SubmitLayout;
    QPushButton *CancelButton;
    QPushButton *NextButton;
    QLabel *DescripionLabel;
    QWidget *page_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *FileNameLabel;
    QLineEdit *NameEdit;
    QLabel *FileNameLabel_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LocationEdit;
    QPushButton *BrowseButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BackButton;
    QPushButton *CreateButton;

    void setupUi(QDialog *NewDialog)
    {
        if (NewDialog->objectName().isEmpty())
            NewDialog->setObjectName(QString::fromUtf8("NewDialog"));
        NewDialog->resize(812, 285);
        NewDialog->setMinimumSize(QSize(812, 285));
        NewDialog->setMaximumSize(QSize(812, 285));
        StackedWidget = new QStackedWidget(NewDialog);
        StackedWidget->setObjectName(QString::fromUtf8("StackedWidget"));
        StackedWidget->setGeometry(QRect(6, 0, 801, 281));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayoutWidget_2 = new QWidget(page);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 801, 201));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        NewItemLayout = new QHBoxLayout();
        NewItemLayout->setObjectName(QString::fromUtf8("NewItemLayout"));
        ProjectTree = new QTreeWidget(verticalLayoutWidget_2);
        ProjectTree->setObjectName(QString::fromUtf8("ProjectTree"));

        NewItemLayout->addWidget(ProjectTree);

        FileTree = new QTreeWidget(verticalLayoutWidget_2);
        FileTree->setObjectName(QString::fromUtf8("FileTree"));

        NewItemLayout->addWidget(FileTree);


        verticalLayout_3->addLayout(NewItemLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ExtensionLabel = new QLabel(verticalLayoutWidget_2);
        ExtensionLabel->setObjectName(QString::fromUtf8("ExtensionLabel"));
        ExtensionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(ExtensionLabel);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayoutWidget_3 = new QWidget(page);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(410, 200, 381, 83));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        ExtensionFrame = new QFrame(verticalLayoutWidget_3);
        ExtensionFrame->setObjectName(QString::fromUtf8("ExtensionFrame"));
        ExtensionFrame->setMinimumSize(QSize(0, 36));
        ExtensionFrame->setMaximumSize(QSize(16777215, 30));
        ExtensionFrame->setFrameShape(QFrame::StyledPanel);
        ExtensionFrame->setFrameShadow(QFrame::Raised);
        ExtensionEdit = new QLineEdit(ExtensionFrame);
        ExtensionEdit->setObjectName(QString::fromUtf8("ExtensionEdit"));
        ExtensionEdit->setGeometry(QRect(0, 0, 381, 36));
        ExtensionEdit->setMinimumSize(QSize(0, 36));

        verticalLayout_4->addWidget(ExtensionFrame);

        SubmitLayout = new QHBoxLayout();
        SubmitLayout->setObjectName(QString::fromUtf8("SubmitLayout"));
        CancelButton = new QPushButton(verticalLayoutWidget_3);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        SubmitLayout->addWidget(CancelButton);

        NextButton = new QPushButton(verticalLayoutWidget_3);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));

        SubmitLayout->addWidget(NextButton);


        verticalLayout_4->addLayout(SubmitLayout);

        DescripionLabel = new QLabel(page);
        DescripionLabel->setObjectName(QString::fromUtf8("DescripionLabel"));
        DescripionLabel->setGeometry(QRect(0, 190, 391, 81));
        DescripionLabel->setTextFormat(Qt::AutoText);
        DescripionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        DescripionLabel->setWordWrap(true);
        StackedWidget->addWidget(page);
        DescripionLabel->raise();
        verticalLayoutWidget_2->raise();
        verticalLayoutWidget_3->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 801, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FileNameLabel = new QLabel(verticalLayoutWidget);
        FileNameLabel->setObjectName(QString::fromUtf8("FileNameLabel"));
        FileNameLabel->setMaximumSize(QSize(800, 40));
        QFont font;
        font.setPointSize(14);
        font.setItalic(true);
        FileNameLabel->setFont(font);
        FileNameLabel->setFrameShape(QFrame::StyledPanel);
        FileNameLabel->setFrameShadow(QFrame::Sunken);
        FileNameLabel->setLineWidth(2);
        FileNameLabel->setMidLineWidth(2);
        FileNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(FileNameLabel);

        NameEdit = new QLineEdit(verticalLayoutWidget);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));

        verticalLayout->addWidget(NameEdit);

        FileNameLabel_2 = new QLabel(verticalLayoutWidget);
        FileNameLabel_2->setObjectName(QString::fromUtf8("FileNameLabel_2"));
        FileNameLabel_2->setMaximumSize(QSize(800, 40));
        QFont font1;
        font1.setPointSize(14);
        FileNameLabel_2->setFont(font1);
        FileNameLabel_2->setFrameShape(QFrame::StyledPanel);
        FileNameLabel_2->setFrameShadow(QFrame::Sunken);
        FileNameLabel_2->setLineWidth(2);
        FileNameLabel_2->setMidLineWidth(2);
        FileNameLabel_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(FileNameLabel_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LocationEdit = new QLineEdit(verticalLayoutWidget);
        LocationEdit->setObjectName(QString::fromUtf8("LocationEdit"));

        horizontalLayout->addWidget(LocationEdit);

        BrowseButton = new QPushButton(verticalLayoutWidget);
        BrowseButton->setObjectName(QString::fromUtf8("BrowseButton"));

        horizontalLayout->addWidget(BrowseButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        BackButton = new QPushButton(verticalLayoutWidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        horizontalLayout_3->addWidget(BackButton);

        CreateButton = new QPushButton(verticalLayoutWidget);
        CreateButton->setObjectName(QString::fromUtf8("CreateButton"));

        horizontalLayout_3->addWidget(CreateButton);


        verticalLayout->addLayout(horizontalLayout_3);

        StackedWidget->addWidget(page_2);

        retranslateUi(NewDialog);

        StackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NewDialog);
    } // setupUi

    void retranslateUi(QDialog *NewDialog)
    {
        NewDialog->setWindowTitle(QApplication::translate("NewDialog", "New", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = ProjectTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("NewDialog", "Project", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = FileTree->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("NewDialog", "File", 0, QApplication::UnicodeUTF8));
        ExtensionLabel->setText(QApplication::translate("NewDialog", "File extension(optional):", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("NewDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        NextButton->setText(QApplication::translate("NewDialog", "Next", 0, QApplication::UnicodeUTF8));
        DescripionLabel->setText(QApplication::translate("NewDialog", "Description: ", 0, QApplication::UnicodeUTF8));
        FileNameLabel->setText(QApplication::translate("NewDialog", "File Name:", 0, QApplication::UnicodeUTF8));
        FileNameLabel_2->setText(QApplication::translate("NewDialog", "Location:", 0, QApplication::UnicodeUTF8));
        BrowseButton->setText(QApplication::translate("NewDialog", "Browse..", 0, QApplication::UnicodeUTF8));
        BackButton->setText(QApplication::translate("NewDialog", "Back", 0, QApplication::UnicodeUTF8));
        CreateButton->setText(QApplication::translate("NewDialog", "Create File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewDialog: public Ui_NewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIALOG_H
