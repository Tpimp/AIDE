#include "buildsystem.h"
#include "ui_buildsystem.h"

BuildSystem::BuildSystem(QStringList arguments, bool GUI, QWidget *parent)
{
    if (GUI)
    {
        ui = new Ui::BuildSystem;//********************************
        mMainWindow = new QMainWindow(parent);//BuildSystem will only create GUI window
        ui->setupUi(mMainWindow);//in an instance of Debug mode, so it has a mainwindow
        mMainWindow->show();//*************************************
        mAideOut = new QFile();//stdout device (would be same for mAideIn)
        mAideOut->open(1, QIODevice::WriteOnly);//integer argument refers to "radio" channel
        foreach (QString  arg, arguments)
        {//currently writes the arguments handed from the parent process over the channel
            //to the parent to display, for debugging purposes, that the arg-list is correct
            mAideOut->write(QString(arg + " ").toAscii());
        }
        mAideOut->flush();//flushes the buffer to ensure clean data delivery
    }
}

BuildSystem::~BuildSystem()
{
    delete mAideOut;
    delete mMainWindow;
    delete ui;
}
