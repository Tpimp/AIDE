#include "newdialog.h"
#include "ui_newdialog.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QItemSelectionModel>
#include <QRect>
#include <QObjectList>
#include <QFileDialog>
#include <aide.h>
NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    connect(ui->CancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->CreateButton, SIGNAL(clicked()), this, SLOT(create()));
    connect(this,SIGNAL(newFileCreated(QString)),(Aide*)parent,SLOT(createFile(QString)));
    connect(ui->ProjectTree, SIGNAL(clicked(QModelIndex)), this, SLOT(selectProject()));
    connect(ui->FileTree, SIGNAL(clicked(QModelIndex)), this, SLOT(selectFile()));
    connect(ui->FileTree, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(setDescription(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(ui->ProjectTree, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(setDescription(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(ui->NextButton,SIGNAL(clicked()), this, SLOT(nextPage()));
    connect(ui->BackButton,SIGNAL(clicked()), this, SLOT(prevPage()));
    connect(ui->BrowseButton,SIGNAL(clicked()),this,SLOT(getDirectory()));


    QTreeWidget * tmpTree = ui->ProjectTree;
    int itemTopCount = 0;
    tmpTree->addTopLevelItem(new QTreeWidgetItem(QStringList("Assembly"),itemTopCount++));
    tmpTree->addTopLevelItem(new QTreeWidgetItem(QStringList("C Project"),itemTopCount++));
    tmpTree->addTopLevelItem(new QTreeWidgetItem(QStringList("C++ Project"),itemTopCount++));
    tmpTree->addTopLevelItem(new QTreeWidgetItem(QStringList("Empty Project"),itemTopCount++));


    tmpTree = ui->FileTree;
    int filecount = itemTopCount;
    QTreeWidgetItem * tmpParent = new QTreeWidgetItem(QStringList("Code"),-1);
    tmpParent->addChild(new QTreeWidgetItem(QStringList("Assembly (.asm)"), filecount++));
    tmpParent->addChild( new QTreeWidgetItem(QStringList("C Document (.c)"),filecount++));
    tmpParent->addChild( new QTreeWidgetItem(QStringList("C++ Document (.cpp)"),filecount++));
    tmpTree->addTopLevelItem(tmpParent);
    tmpTree->addTopLevelItem(new QTreeWidgetItem(QStringList("Other"),filecount));
    ui->ExtensionFrame->hide();
}

NewDialog::~NewDialog()
{
    delete ui;
}

void NewDialog::create()
{
    QTreeWidgetItem * currentItem = ui->FileTree->currentItem();
    if(currentItem->type() == -1)
        return;
    else
        if(currentItem->type() >= ui->ProjectTree->topLevelItemCount())
        {
            QString ext;
            if(currentItem->text(0) == "Other")
            {
                ext = ui->ExtensionEdit->text();
            }
            else
            {
                ext = currentItem->text(0);
            }
            ext = ext.section("",(ext.indexOf('.')+1),ext.indexOf(')'));
            QString filepath = ui->LocationEdit->text();
            QString filename = ui->NameEdit->text();
            if(!filepath.endsWith('/'))
                filepath += '/';
            filepath += filename;
            filepath += ext;
            emit newFileCreated(filepath);
        }
        close();
}

void NewDialog::getDirectory()
{
    QString filepath = QFileDialog::getExistingDirectory(this,"Location to create Project/File",QDir::currentPath());
    if(filepath != "")
    {
        ui->LocationEdit->setText(filepath);
    }
}

void NewDialog::open()
{
    ui->StackedWidget->setCurrentIndex(0);
    this->show();
}

void NewDialog::nextPage()
{
    ui->StackedWidget->setCurrentIndex(ui->StackedWidget->currentIndex() > ui->StackedWidget->count() ? (ui->StackedWidget->count() -1) : (ui->StackedWidget->currentIndex() +1));
}

void NewDialog::prevPage()
{
    ui->StackedWidget->setCurrentIndex(ui->StackedWidget->currentIndex() > 0 ? (ui->StackedWidget->currentIndex() -1) : 0);
}

void NewDialog::selectProject()
{
    QTreeWidgetItem * currentItem = ui->FileTree->currentItem();
    if (currentItem)
        currentItem->setSelected(false);
    ui->ExtensionFrame->hide();
    switch(ui->ProjectTree->currentItem()->type())
    {
    case 0:ui->DescripionLabel->setText("Description:\nCreates a new project with an assembly file as the\n entry to the program.");break;
    case 1:ui->DescripionLabel->setText("Description:\nCreates a new project with a C file as the entry to\n the program.");break;
    case 2:ui->DescripionLabel->setText("Description:\nCreates a new project with a C++ file as the entry\n to the program.");break;
    case 3:ui->DescripionLabel->setText("Description:\nCreates a new empty project.");break;
    default: ui->DescripionLabel->setText("Description:");break;
    }

}

void NewDialog::selectFile()
{
    if(ui->FileTree->currentItem()->type() != -1)
    {
        if(ui->ProjectTree->currentItem())
           ui->ProjectTree->currentItem()->setSelected(false);
        ui->ExtensionFrame->hide();
        switch(ui->FileTree->currentItem()->type())
        {
        case 4:ui->DescripionLabel->setText("Description:\nCreates a new Assembly File with the extension .asm");break;
        case 5:ui->DescripionLabel->setText("Description:\nCreates a new C File with the extension .c");break;
        case 6:ui->DescripionLabel->setText("Description:\nCreates a new C++ File with the extension .cpp");break;
        case 7:ui->DescripionLabel->setText("Description:\nCreates a new file with an optional user defined\n extension");ui->ExtensionFrame->show();break;
        default: ui->DescripionLabel->setText("Description:");break;
        }
    }
    else
        ui->FileTree->currentItem()->setSelected(false);

}

void NewDialog::setDescription(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(current)
    {
            ui->ExtensionFrame->hide();
            switch(current->type())
            {
            case 0:ui->DescripionLabel->setText("Description:\nCreates a new project with an assembly file as the\n entry to the program.");break;
            case 1:ui->DescripionLabel->setText("Description:\nCreates a new project with a C file as the entry to\n the program.");break;
            case 2:ui->DescripionLabel->setText("Description:\nCreates a new project with a C++ file as the entry\n to the program.");break;
            case 3:ui->DescripionLabel->setText("Description:\nCreates a new empty project.");break;
            case 4:ui->DescripionLabel->setText("Description:\nCreates a new Assembly File with the extension .asm");break;
            case 5:ui->DescripionLabel->setText("Description:\nCreates a new C File with the extension .c");break;
            case 6:ui->DescripionLabel->setText("Description:\nCreates a new C++ File with the extension .cpp");break;
            case 7:ui->DescripionLabel->setText("Description:\nCreates a new file with an optional user defined\n extension");ui->ExtensionFrame->show();break;
            default: ui->DescripionLabel->setText("Description:");break;
            }
    }
    else
    {
        ui->DescripionLabel->setText("Description:");
    }
}


