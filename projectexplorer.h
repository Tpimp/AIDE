#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QDockWidget>

namespace Ui {
class ProjectExplorer;
}

class ProjectExplorer : public QDockWidget
{
    Q_OBJECT
public:

    explicit ProjectExplorer(QWidget *parent = 0);
    void openProject(QString project_file = "");
    ~ProjectExplorer();
private:
    Ui::ProjectExplorer * ui;

signals:
    
public slots:
    
};

#endif // PROJECTEXPLORER_H
