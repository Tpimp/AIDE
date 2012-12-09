#include "aide.h"
#include "ui_aide.h"

Aide::Aide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Aide)
{
    ui->setupUi(this);
    connect(ui->ActionExit,SIGNAL(triggered()),this,SLOT(close()));
}

Aide::~Aide()
{
    delete ui;
}
