#ifndef BUILDSYSTEM_H
#define BUILDSYSTEM_H

#include <QMainWindow>
#include <QStringList>
#include <QProcess>
#include <QFile>
#include <QList>
#include "terminalcontroller.h"

//AIDE talks on 0/1
//GDB talks on 2/3/4
//GCC/NASM/LINKER talks on 5/6

namespace Ui {
class BuildSystem;
}

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
    TerminalController * mTerminal;
    void setupAideCommunications();
    void parseArguments(QStringList arguments);

};

#endif // BUILDSYSTEM_H
