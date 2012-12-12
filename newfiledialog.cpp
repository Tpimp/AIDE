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
    connect(ui->CreateButton,SIGNAL(clicked()),this,SLOT(createFile()));
    connect(ui->CreateButton,SIGNAL(fileAdded(QString filepath)),(Aide*)parent,SLOT(createFile(QString filepath)));
    connect(ui->DirectoryBrowserButton,SIGNAL(clicked()),this,SLOT(findDirectory()));
}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}



void NewFileDialog::createFile()
{
    qDebug() << ui->FileNameInput->text() << " " << ui->LocationInput->text();
    emit fileAdded(ui->LocationInput->text());
    ui->FileNameInput->clear();
    ui->LocationInput->clear();
    this->close();
}


void NewFileDialog::findDirectory()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save To...");
    if(filename != "" )
    {
        ui->LocationInput->setText(filename);
    }

}
