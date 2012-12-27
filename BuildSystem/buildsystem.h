#ifndef BUILDSYSTEM_H
#define BUILDSYSTEM_H

#include <QMainWindow>
#include <QStringList>
#include <QProcess>
#include <QFile>
#include <QList>
#include "processcontroller.h"

//AIDE talks on 0/1
//GDB talks on 2/3/4
//GCC/NASM/LINKER talks on 5/6

namespace Ui {
class BuildSystem;
}

enum Arguments
{
    Build_Mode = 1,
    Run_Mode = 2,
    Project = 3
};


class BuildSystem : public QObject
{
public://uses the GUI boolean established in main to determine if debug window needs to show
    explicit BuildSystem(QStringList arguments, bool GUI, QWidget *parent = 0);
    ~BuildSystem();

private:
    Ui::BuildSystem *ui;
    QMainWindow * mMainWindow;
    QFile * mAideIn;//communication channels between
    QFile * mAideOut;//buildsystem and aide parent process
    QString mTerminalPath;
    int mNumberFilesToCompile;
    QStringList mTerminalCompileFiles;
    QString mBuildName;
    QString mRunMode;
    QString mBuildMode;
    ProcessController * mTerminal;
    void setupAideCommunications();
    void parseArguments(QStringList arguments);

};

#endif // BUILDSYSTEM_H
