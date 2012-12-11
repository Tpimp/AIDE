#include "newfiledialog.h"
#include "ui_newfiledialog.h"
#include <QFileDialog>
#include <QDebug>
NewFileDialog::NewFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);    // Set
    connect(ui->CreateButton,SIGNAL(clicked()),this,SLOT(createFile()));
    connect(ui->DirectoryBrowserButton,SIGNAL(clicked()),this,SLOT(findDirectory()));
    this->setA
}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}



void NewFileDialog::createFile()
{
    qDebug() << ui->FileNameInput->text() << " " << ui->LocationInput->text();
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
