#include "aide.h"
#include "ui_aide.h"


Aide::Aide(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Aide)
{
    ui->setupUi(this);
    mNewFileDialog = new NewFileDialog(this);
    connect(ui->ActionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->ActionAssembly_x86,SIGNAL(triggered()),mNewFileDialog, SLOT(open()));
}



bool Aide::addNewProject(ProjectFile *newProject)
{
    if(newProject) // If newProject is not NULL
    {
        mOpenProjects.append(newProject); // add it to open project list
    }
    return newProject;
}



Aide::~Aide()
{
    delete ui;
}
