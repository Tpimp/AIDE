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
    addNewProject();
}

bool Aide::addFileToProject(int project_index, FileInfo *file)
{
    int count = mOpenProjects.count();
    if(project_index >= 0 && project_index < count)
    {
        ProjectFile * project = mOpenProjects.at(project_index);
        project->addFile(file);
        return true;
    }
    return false;
}

void Aide::createFile(QString filepath)
{

}

bool Aide::addNewProject(ProjectFile *newProject)
{
    if(newProject) // If newProject is not NULL
    {
        mOpenProjects.append(newProject); // add it to open project list
    }
    else
    {
        ProjectFile * ptr = new ProjectFile("",this);
        mOpenProjects.append(ptr); // add it to open project list
    }
    return newProject;
}

ProjectFile * Aide::getProject(int project_index)
{
    return mOpenProjects.at(project_index);
}

Aide::~Aide()
{
    delete ui;
    int length = mOpenProjects.length();
    ProjectFile * ptr = 0;
    for(int index = 0; index < length; index++)
    {
        ptr = mOpenProjects.at(index);
        delete ptr;
    }

}
