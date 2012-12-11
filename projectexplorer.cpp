#include "projectexplorer.h"
#include "ui_projectexplorer.h"
ProjectExplorer::ProjectExplorer(QWidget *parent) :
    QDockWidget(parent), ui(new Ui::ProjectExplorer)
{

    ui->setupUi(this);
    setGeometry(0,0,260,1080);
    setStyleSheet(
                     "QDockWidget::title{ position: absolute; padding-left: 3px;text-align: center; background-color: blue; border: 2px solid black; }"
                     "QDockWidget { color: yellow; font bold 20px; border: 2px solid black; }"
                 );  // set the dock widget title style
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea); // Set this dock widget for only left and ride sides
}

void ProjectExplorer::openProject(ProjectFile * project_file)
{
}


ProjectExplorer::~ProjectExplorer()

{
    delete ui;
}
