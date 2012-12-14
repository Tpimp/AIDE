#include "aide.h"
#include "ui_aide.h"

#include <QDebug>


Aide::Aide(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Aide), mProjectExplorer(new ProjectExplorer(this)),mEditor(new Editor(this))
{
    ui->setupUi(this);
    mNewFileDialog = new NewFileDialog(this);
    mNewProjectDialog = new NewProjectDialog(this);
    connect(ui->ActionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->ActionAssembly_x86,SIGNAL(triggered()),mNewFileDialog, SLOT(open()));
    connect(ui->ActionNew_Project,SIGNAL(triggered()),mNewProjectDialog, SLOT(open()));
    addDockWidget(Qt::LeftDockWidgetArea,mProjectExplorer,Qt::Vertical);
    setCentralWidget(mEditor);
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

    //type = getFiletype(filepath);
    FileInfo * file_info = new FileInfo;
    FileInfo info = mProjectExplorer->addFile(filepath, "Code");
    file_info->mDir = info.mDir;
    file_info->mFilename = info.mFilename;
    file_info->mPath = info.mPath;
    file_info->mType = info.mType;
    ProjectFile * current_project = mOpenProjects.at(mProjectExplorer->currentProject());
    current_project->addFile(file_info);
}

void Aide::createProject(QString projectPath)
{
  //  int current_project = mProjectExplorer
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
    delete mEditor;
    delete mProjectExplorer;
    int length = mOpenProjects.length();
    ProjectFile * ptr = 0;
    for(int index = 0; index < length; index++)
    {
        ptr = mOpenProjects.at(index);
        delete ptr;
    }

}
