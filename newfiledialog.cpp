#include "newfiledialog.h"
#include "ui_newfiledialog.h"
#include <QFileDialog>
#include <aide.h>
#include <QDebug>
NewFileDialog::NewFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);    // Set
    ui->FileNameInput->setText("<NewFile.asm>");
    ui->LocationInput->setText(QDir::currentPath() + QDir::separator() + ui->FileNameInput->text() );

    connect(ui->CreateButton,SIGNAL(clicked()),this,SLOT(createFile()));
    connect(this,SIGNAL(fileAdded(QString)),(Aide*)parent,SLOT(createFile(QString)));
    connect(ui->DirectoryBrowserButton,SIGNAL(clicked()),this,SLOT(findDirectory()));
    connect(ui->FileNameInput, SIGNAL(textChanged(QString)), this,SLOT(setName(QString)));

}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}

void NewFileDialog::createFile()
{
    emit fileAdded(ui->LocationInput->text());
    ui->FileNameInput->clear();
    ui->LocationInput->clear();
    this->close();
}


void NewFileDialog::findDirectory()
{

    QString dirPath = QFileDialog::getExistingDirectory(this,"Save To...");//QFileDialog::getSaveFileName(this,"Save To...");
    if(dirPath != "" )
    {
        ui->LocationInput->setText(dirPath + "/" +  ui->FileNameInput->text());
    }

}

void NewFileDialog::setName(QString newName)
{
    QString tmp = ui->LocationInput->text();
    int location = tmp.lastIndexOf('/');
    tmp = tmp.remove(location + 1, tmp.count()-1);
    tmp += newName;
    ui->LocationInput->setText(tmp);
}
