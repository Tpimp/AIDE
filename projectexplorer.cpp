#include "projectexplorer.h"
#include "ui_projectexplorer.h"
ProjectExplorer::ProjectExplorer(QWidget *parent) :
    QDockWidget(parent), ui(new Ui::ProjectExplorer)
{
    ui->setupUi(this);
    this->setStyleSheet(
    "QDockWidget::title{ position: absolute; padding-left: 3px;text-align: center; background-color: blue;}"
    "QDockWidget { color: yellow; font bold 20px; }"
                      );
}


ProjectExplorer::~ProjectExplorer()

{
    delete ui;
}
