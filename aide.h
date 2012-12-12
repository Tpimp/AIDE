#ifndef AIDE_H
#define AIDE_H

#include <QMainWindow>
#include <newfiledialog.h>
#include <QList>
#include <projectfile.h>
#include <file_info.h>
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
        NewFileDialog * mNewFileDialog;
        QList<ProjectFile *> mOpenProjects;
        QList<QStringList>   mFileTypes;   // ADD INITIALIZE FILES TYPES
    public slots:
        void createFile(QString filepath);
};

#endif // AIDE_H
