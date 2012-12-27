#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QDockWidget>
#include <projectfile.h>
#include <QIcon>
#include <QMenu>

namespace Ui {
class ProjectExplorer;
}

class ProjectExplorer : public QDockWidget
{
    Q_OBJECT
public:

    explicit ProjectExplorer(QWidget *parent = 0);
    void addProject(QString name);
    void createEmptyProject();
    void openProject(ProjectFile * project_file = 0);
    FileInfo addFile(QString filepath, QString type);
    void addFilter(QString filter);
    int currentProject(){return mCurrentProject;}
    QString getIcon(FileInfo fileinfo);
    QMenu * conextMenu(){return mProjectMenu;}
    ~ProjectExplorer();
private:
    Ui::ProjectExplorer * ui;
    int mCurrentProject;
    QIcon mFilterIcon;
    QMenu * mProjectMenu;
signals:
    
public slots:
    void openContextMenu(QPoint pos);
    void setCurrentProject(int index);
    void fillTreeWidget(ProjectFile * project);
    
};

#endif // PROJECTEXPLORER_H
