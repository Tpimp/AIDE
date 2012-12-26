#include "buildsystem.h"
#include "ui_buildsystem.h"

BuildSystem::BuildSystem(QStringList arguments, bool GUI, QWidget *parent)
    : mTerminalPath("sudo '/usr/bin/gnome-terminal'"), mNumberFilesToCompile(0)
{
    parseArguments(arguments);//arguments is empty and should not be used after this function call
    //^^after this call we have the bulid name and the files to compile
    mTerminal = new TerminalController(mBuildName, this);
    mTerminal->start(mTerminalPath);
    setupAideCommunications();
    if (GUI)
    {
        ui = new Ui::BuildSystem;//********************************
        mMainWindow = new QMainWindow(parent);//BuildSystem will only create GUI window
        ui->setupUi(mMainWindow);//in an instance of Debug mode, so it has a mainwindow
        mMainWindow->show();//*************************************
    }
}

void BuildSystem::parseArguments(QStringList arguments)
{
    if (!arguments.isEmpty())
    {
        arguments.removeFirst();//removes unecessary buildsystem filepath arg
        arguments.removeFirst();//removes unecessary build mode arg
        mBuildName = arguments.takeFirst();//takes the build name for file linking
        foreach(QString arg, arguments)
        {
            mTerminalCompileFiles << arg;
            ++mNumberFilesToCompile;//number will always be 1 greater than true last index
        }
        arguments.clear();//wipes original arguments list
    }
}

void BuildSystem::setupAideCommunications()
{
    mAideOut = new QFile();
    mAideIn = new QFile();

    mAideOut->open(1, QIODevice::WriteOnly);
    mAideIn->open(0, QIODevice::ReadOnly);

}


BuildSystem::~BuildSystem()
{
    mAideIn->close();
    mAideOut->close();
    delete mAideIn;
    delete mAideOut;
    delete mMainWindow;
    delete ui;
}
