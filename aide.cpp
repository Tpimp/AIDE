#include "aide.h"
#include "ui_aide.h"

#include <QDebug>
#include <QDir>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
typedef QPair<QString, QStringList > Pair;

Aide::Aide(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Aide), mProjectExplorer(new ProjectExplorer(this)),mEditor(new Editor(this)),
      mBuildSystemPath("./data/bin/BuildSystem")
{
    // Load UI and configure embedded widgets
    ui->setupUi(this);
    mNewDialog = new NewDialog(this);
    mBuildSystemProcess = new QProcess(this);
    addDockWidget(Qt::LeftDockWidgetArea,mProjectExplorer,Qt::Vertical);
    setCentralWidget(mEditor);
    loadKnownFileTypes();                 //load the known file types file Data/Startup/


    // For testing Save Project
    ProjectFile * project = new ProjectFile("test.aid","/home/christopher/Desktop/AIDE/",this);
    project->addFilter("Code");
    project->addFilter("Other");
    FileInfo * fileinfo = new FileInfo;
    fileinfo->mPath = "FilePath";
    fileinfo->mType = "Code";
    fileinfo->mFilename = "file.code";
    fileinfo->mBreakpoints.append(25);
    fileinfo->mBreakpoints.append(26);
    fileinfo->mBreakpoints.append(29);
    fileinfo->mBreakpoints.append(231);
    fileinfo->mBreakpoints.append(250);
    fileinfo->mBreakpoints.append(252);
    fileinfo->mDir = "AIDE";
    fileinfo->mRelativePath = "/AIDE";
    project->addFile(fileinfo);
    addNewProject(project->name(),project->filePath(),project);
}


bool Aide::addNewProject(QString name, QString filepath, ProjectFile *newProject)
{
    if(newProject) // If newProject is not NULL
    {
        mOpenProjects.append(newProject); // add it to open project list
        mProjectExplorer->addProject(name);
        mProjectExplorer->fillTreeWidget(newProject);
    }
    else
    {
        ProjectFile * ptr = new ProjectFile(name, filepath,this);
        mProjectExplorer->addProject(name);
        mProjectExplorer->createEmptyProject();
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

void Aide::Connections()
{
    connect(ui->ActionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->ActionNew,SIGNAL(triggered()),mNewDialog, SLOT(open()));
    connect(ui->ActionBuild_and_Run, SIGNAL(triggered()), this, SLOT(setRun()));
    connect(ui->ActionBuild_and_Debug, SIGNAL(triggered()), this, SLOT(setDebug()));
    connect(ui->ActionClean, SIGNAL(triggered()), this, SLOT(setClean()));
    connect(ui->ActionReBuild, SIGNAL(triggered()), this, SLOT(setReBuild()));
    QAction * new_file = mProjectExplorer->conextMenu()->actions()[0];
    QAction * existing_file = mProjectExplorer->conextMenu()->actions()[1];
    connect(existing_file,SIGNAL(triggered()),this,SLOT(createExisting()));
    connect(new_file,SIGNAL(triggered()),mNewDialog,SLOT(open()));
    connect(ui->ActionProject,SIGNAL(triggered()),this,SLOT(saveProject()));

}


void Aide::createExisting()
{
    QString file = QFileDialog::getOpenFileName(this,"Add Existing File to Project",QDir::currentPath());
    if(file != "")
    {
        createFile(file);
    }
}

void Aide::createFile(QString filepath)
{
    qDebug() << "Creating file at:" << filepath;
    //type = getFiletype(filepath);
    FileInfo * file_info = new FileInfo;
    QString filter = getFilter(QString(filepath));
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


void Aide::writeKnownFileTypes()
{
    QFile output(QDir::currentPath() + "/data/startup/known_types.conf");
    QString data;
    QXmlStreamWriter writer(&data);
    writer.setAutoFormatting(true);
    writer.setAutoFormattingIndent(true);
    writer.writeStartDocument();
    writer.writeStartElement("known_types.conf");
    writer.writeAttribute("Purpose", "Define known filters and file types");
    foreach (Pair filter, mKnownFileTypes) //Pair is a typdef see top of file
    {

        writer.writeStartElement("Filter");
        writer.writeTextElement("Name",filter.first);
        foreach (QString type, filter.second)
        {
            writer.writeTextElement("Type",type);
        }
        writer.writeEndElement();
    }

    writer.writeEndDocument();
    output.open(QIODevice::WriteOnly);
    output.write(data.toAscii());
    output.flush();
    output.close();

}

void Aide::loadKnownFileTypes()
{
    QFile input(QDir::currentPath() + "/data/startup/known_types.conf");
    input.open(QIODevice::ReadOnly);
    QString file(input.readAll());
    input.close();
    QXmlStreamReader reader(file);
    QXmlStreamReader::TokenType token;
    QPair<QString,QStringList> current;
    QString Filter;
    QString Type;
    QString Name;
    QString * current_string;
    while(!reader.atEnd())
    {
        token = reader.readNext();
        switch(token)
        {
            case QXmlStreamReader::StartElement:
            {
                if(reader.name().toString() == "Name")
                {
                    current.first  = reader.text().toString();
                    current_string = &current.first;
                }
                else if( reader.name() == "Type")
                {
                    current_string = &Name;
                }
                else
                {
                    current_string = 0;
                }
                break;
            }
            case QXmlStreamReader::Characters:
            {
                Name = reader.name().toString();
                if(current_string)
                    if(!reader.text().toString().contains('\n'))
                    {
                        if(current_string == &current.first)
                            *current_string = reader.text().toString();
                        else
                            current.second.append(reader.text().toString());
                    }
                break;
            }
            case QXmlStreamReader::EndElement:
            {
                if(reader.name().toString() == "Filter")
                {
                    mKnownFileTypes.append(QPair<QString,QStringList>(current));
                    current.second.clear();
                }
                break;
            }
            default: break;
        }
    }
}

void Aide::saveProject()
{
    int current_project = mProjectExplorer->currentProject();        //Get the current project count
    if(mOpenProjects.count() > current_project)                      //If the project is valid
    {
        ProjectFile * project = mOpenProjects.at(current_project);   //Get the project file pointer
        project->saveProject();                                      //Save its current state
    }
}

void Aide::setDebug()
{
    mBuildSystemMode = "Debug";
    startBuildSystem(mBuildSystemMode);
}

void Aide::setRun()
{
    mBuildSystemMode = "Run";
    startBuildSystem(mBuildSystemMode);
}

void Aide::setClean()
{
    mBuildSystemMode = "Clean";
    startBuildSystem(mBuildSystemMode);
}

void Aide::setReBuild()
{
    mBuildSystemMode = "Rebuild";
    startBuildSystem(mBuildSystemMode);
}


void Aide::startBuildSystem(QString build_mode /*add files_to_compile string_list*/)
{
    QStringList BuildSystemArguments;
    BuildSystemArguments << build_mode;//list of args to pass to buildsystem
    //                              these args will be filled with:
    //                              file_path (default 1st string)
    //                              build_mode (defined 2nd string)
    //                              program_to_build_name (defined 3rd string)
    //                              files to compile (will add a string foreach file) <<--perhaps create as data member so no parameter is needed
    //                              I can write a function to check these guys later ^^ (files)
    mBuildSystemProcess->start(mBuildSystemPath, BuildSystemArguments);
    mBuildSystemProcess->setProcessChannelMode(QProcess::MergedChannels);
    connect(mBuildSystemProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readBytes()));
}

//BUILDSYSTEM talks on 0/1
//QDEBUG talks on 2

void Aide::readBytes()
{
    QString strin = mBuildSystemProcess->readAllStandardOutput();
    qDebug() << strin;
}


Aide::~Aide()
{
    // writeKnowFileTypes();
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


