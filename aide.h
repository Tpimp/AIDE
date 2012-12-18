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


namespace Ui
{
    class Aide;
}

class Aide : public QMainWindow
{
        Q_OBJECT

    public:
        explicit Aide(QWidget *parent = 0);
        bool addNewProject(ProjectFile * newProject = 0);
        bool addFileToProject(int project_index,FileInfo * file);
        ProjectFile * getProject(int project_index);
        ~Aide();

    private:
        Ui::Aide *ui;
        NewDialog * mNewDialog;
        QList<ProjectFile *> mOpenProjects;
        QList<QStringList>   mFileTypes;   // ADD INITIALIZE FILES TYPES
        ProjectExplorer * mProjectExplorer;
        Editor * mEditor;
        QList<QPair< QString, QStringList > > mKnownFileTypes;
        QList<QPair< QString, QStringList > > mKnownMimeTypes;
        QString getFilter(QString filepath);
        void writeKnownFileTypes();
        void loadKnownFileTypes();
    public slots:
        void createFile(QString filePath);
        void createProject(QString projectPath);
};

#endif // AIDE_H
