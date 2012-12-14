#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include <QFileDialog>
#include <aide.h>
#include <QDebug>
NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);    // Set
    ui->ProjectNameInput->setText("<NewProject.pro>");
    ui->LocationInput->setText(QDir::currentPath() + QDir::separator() + ui->ProjectNameInput->text() );

    connect(ui->CreateButton,SIGNAL(clicked()),this,SLOT(createProject()));
    connect(this,SIGNAL(projectAdded(QString)),(Aide*)parent,SLOT(createProject(QString)));
    connect(ui->DirectoryBrowserButton,SIGNAL(clicked()),this,SLOT(findDirectory()));
    connect(ui->ProjectNameInput, SIGNAL(textChanged(QString)), this,SLOT(setName(QString)));
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

void NewProjectDialog::createProject()
{
    emit projectAdded(ui->LocationInput->text());
    ui->ProjectNameInput->clear();
    ui->LocationInput->clear();
    this->close();
}


void NewProjectDialog::findDirectory()
{

    QString dirPath = QFileDialog::getExistingDirectory(this,"Save To...");//QFileDialog::getSaveFileName(this,"Save To...");
    if(dirPath != "" )
    {
        ui->LocationInput->setText(dirPath + "/" +  ui->ProjectNameInput->text());
    }

}

void NewProjectDialog::setName(QString newName)
{
    QString tmp = ui->LocationInput->text();
    int location = tmp.lastIndexOf('/');
    tmp = tmp.remove(location + 1, tmp.count()-1);
    tmp += newName;
    ui->LocationInput->setText(tmp);
}
