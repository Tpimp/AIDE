#include "newdialog.h"
#include "ui_newdialog.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QItemSelectionModel>
#include <QRect>

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    connect(ui->CancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->CreateButton, SIGNAL(clicked()), this, SLOT(create()));
    connect(ui->ProjectTree, SIGNAL(clicked(QModelIndex)), this, SLOT(selectProject()));
    connect(ui->FileTree, SIGNAL(clicked(QModelIndex)), this, SLOT(selectFile()));

    QTreeWidget * tmpTree = ui->FileTree;
    int itemTopCount = 0;
    QTreeWidgetItem * tmpParent = new QTreeWidgetItem(QStringList("Code"),-1);

    int itemSubCount = 0;
    tmpParent->addChild(new QTreeWidgetItem(QStringList("Assembly (.asm)"), itemSubCount++));
    tmpParent->addChild( new QTreeWidgetItem(QStringList("C Document (.c)"),itemSubCount++));
    tmpParent->addChild( new QTreeWidgetItem(QStringList("C++ Document (.cpp)"),itemSubCount++));


    tmpTree->insertTopLevelItem(0,tmpParent);
    tmpTree->insertTopLevelItem(1,new QTreeWidgetItem(QStringList("Other"),itemSubCount));

    itemTopCount = 0;
    tmpTree = ui->ProjectTree;
    tmpTree->insertTopLevelItem(0,new QTreeWidgetItem(QStringList("Assembly"),itemTopCount++));
    tmpTree->insertTopLevelItem(1,new QTreeWidgetItem(QStringList("C Project"),itemTopCount++));
    tmpTree->insertTopLevelItem(2,new QTreeWidgetItem(QStringList("C++ Project"),itemTopCount++));
    tmpTree->insertTopLevelItem(3,new QTreeWidgetItem(QStringList("Empty Project"),itemTopCount));
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
        close();
}

void NewDialog::selectProject()
{
    QTreeWidgetItem * currentItem = ui->FileTree->currentItem();
    if (ui->ProjectTree->currentItem()->type() != -1)
    {
        if (currentItem)
            currentItem->setSelected(false);
        switch(ui->ProjectTree->currentItem()->type())
        {
        case 0:ui->DescripionLable->setText("Description:\nCreates a new project with an assembly file as the\n entry to the program.");break;
        case 1:ui->DescripionLable->setText("Description:\nCreates a new project with a C file as the entry to\n the program.");break;
        case 2:ui->DescripionLable->setText("Description:\nCreates a new project with a C++ file as the entry\n to the program.");break;
        case 3:ui->DescripionLable->setText("Description:\nCreates a new empty project.");break;
        default: ui->DescripionLable->setText("Description:");break;
        }
    }
    //switch(currentItem->)
}

void NewDialog::selectFile()
{
    if(ui->FileTree->currentItem()->type() != -1)
    {
        if(ui->ProjectTree->currentItem())
           ui->ProjectTree->currentItem()->setSelected(false);
        switch(ui->FileTree->currentItem()->type())
        {
        case 0:ui->DescripionLable->setText("Description:\nCreates a new Assembly File with the extension .asm");break;
        case 1:ui->DescripionLable->setText("Description:\nCreates a new C File with the extension .c");break;
        case 2:ui->DescripionLable->setText("Description:\nCreates a new C++ File with the extension .cpp");break;
        case 3:ui->DescripionLable->setText("Description:\nCreates a new file with a optional user defined\n extension");break;
        default: ui->DescripionLable->setText("Description:");break;
        }
    }
    else
        ui->FileTree->currentItem()->setSelected(false);

}

void NewDialog::setDescription()
{

}


