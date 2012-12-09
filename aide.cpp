#include "aide.h"
#include "ui_aide.h"

Aide::Aide(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Aide)
{
    ui->setupUi(this);
    m_NewFileDialog = new NewFileDialog(this);
    connect(ui->ActionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionAssembly_x86,SIGNAL(triggered()),m_NewFileDialog, SLOT(open()));
}

Aide::~Aide()
{
    delete ui;
}
