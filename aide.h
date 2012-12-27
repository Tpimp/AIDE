#ifndef AIDE_H
#define AIDE_H

#include <QMainWindow>
#include <QList>
#include <projectfile.h>
#include <file_info.h>
#include <projectexplorer.h>
#include "editor.h"
#include "newdialog.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QProcess>

namespace Ui
{
    class Aide;
}



class Aide : public QMainWindow
{
        Q_OBJECT

    public:
        explicit Aide(QWidget *parent = 0);
        bool addNewProject(QString name, QString filepath, ProjectFile * newProject = 0);
        bool addFileToProject(int project_index,FileInfo * file);
        ProjectFile * getProject(int project_index);
        void startBuildSystem(QString build_mode);
        ~Aide();

    private:
        Ui::Aide *ui;
        NewDialog * mNewDialog;
        QList<ProjectFile *> mOpenProjects;
        QList<QStringList>   mFileTypes;   // ADD INITIALIZE FILES TYPES
        ProjectExplorer * mProjectExplorer;
        Editor * mEditor;
        QProcess * mBuildSystemProcess;
        QString mBuildSystemPath;
        QList<QPair< QString, QStringList > > mKnownFileTypes;
        QList<QPair< QString, QStringList > > mKnownMimeTypes;
        QString getFilter(QString filepath);
        QString mBuildSystemMode;
        void writeKnownFileTypes();
        void loadKnownFileTypes();
        void Connections();
    public slots:
        void createExisting();
        void createFile(QString filePath);
        void createProject(QString projectPath);
        void readBytes();
        void saveProject();
        void setDebug();
        void setRun();
        void setClean();
        void setReBuild();
};

#endif // AIDE_H
