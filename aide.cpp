#include "aide.h"
#include "ui_aide.h"

#include <QDebug>

typedef QPair<QString, QStringList > Pair;

Aide::Aide(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Aide), mProjectExplorer(new ProjectExplorer(this)),mEditor(new Editor(this))
{
    ui->setupUi(this);
    mNewDialog = new NewDialog(this);
    connect(ui->ActionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->ActionNew,SIGNAL(triggered()),mNewDialog, SLOT(open()));
    addDockWidget(Qt::LeftDockWidgetArea,mProjectExplorer,Qt::Vertical);
    setCentralWidget(mEditor);
    loadKnownFileTypes();
    addNewProject();
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
    qDebug() << "Creating file at:" << filepath;
    //type = getFiletype(filepath);
    FileInfo * file_info = new FileInfo;
    QString filter = getFilter(filepath);
    FileInfo info = mProjectExplorer->addFile(filepath, filter);
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

QString Aide::getFilter(QString filepath)
{
    QString exit_str;
    bool FOUND = false;
    QString ext = filepath.remove(0,filepath.lastIndexOf('.')+1);
    foreach (Pair filter, mKnownFileTypes) //Pair is a typdef see top of file
    {
        foreach (QString type, filter.second)
        {
            if(type == ext)
            {
                exit_str = filter.first;
                FOUND = true;
                break;
            }
        }
        if(FOUND)
            break;
    }
    return exit_str;
}

ProjectFile * Aide::getProject(int project_index)
{
    return mOpenProjects.at(project_index);
}

void Aide::loadKnownFileTypes()
{
    //eventually load from a file
    QStringList types;
    types.append("asm");
    types.append("cpp");
    types.append("c");
    mKnownFileTypes.append(QPair<QString,QStringList>(QString("Code"),types));
    types.clear();
    types.append("txt");
    mKnownFileTypes.append(QPair<QString,QStringList>(QString("Other"),types));
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


