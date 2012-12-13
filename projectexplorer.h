#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QDockWidget>
#include <projectfile.h>


namespace Ui {
class ProjectExplorer;
}

class ProjectExplorer : public QDockWidget
{
    Q_OBJECT
public:

    explicit ProjectExplorer(QWidget *parent = 0);
    void createEmptyProject();
    void openProject(ProjectFile * project_file = 0);
    void addFile(QString filepath, QString type);
    int currentProject(){return mCurrentProject;}
    ~ProjectExplorer();
private:
    Ui::ProjectExplorer * ui;
    int mCurrentProject;
signals:
    
public slots:
    void setCurrentProject(int index);
    
};

#endif // PROJECTEXPLORER_H
