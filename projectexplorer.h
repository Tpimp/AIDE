#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QDockWidget>
#include <projectfile.h>
#include <aide.h>

namespace Ui {
class ProjectExplorer;
}

class ProjectExplorer : public QDockWidget
{
    Q_OBJECT
public:

    explicit ProjectExplorer(QWidget *parent = 0);
    void openProject(ProjectFile * project_file = 0);
    ~ProjectExplorer();
private:
    Ui::ProjectExplorer * ui;

signals:
    
public slots:
    
};

#endif // PROJECTEXPLORER_H
