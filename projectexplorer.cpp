#include "projectexplorer.h"
#include "ui_projectexplorer.h"
#include <QTreeWidgetItem>
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
    createEmptyProject();
}


void ProjectExplorer::addFile(QString filepath, QString type)
{
    QFile file(filepath);
    FileInfo fileinfo;
    fileinfo.mFilename = file.fileName();
    fileinfo.mPath = filepath;
    fileinfo.mDir = filepath;
    fileinfo.mType = type;
    fileinfo.mPath.remove(fileinfo.mFilename);
    int location = filepath.lastIndexOf('/');
    fileinfo.mDir = filepath.remove(0,location);
    int filters = ui->TreeWidget->topLevelItemCount();
    bool TYPEFOUND = false;
    int found_at = 0;
    QTreeWidgetItem * parent = 0;
    for (int index = 0; index < filters; index ++)
    {
        QTreeWidgetItem * item = ui->TreeWidget->topLevelItem(index);
        if(type == item->text(0))
        {
            TYPEFOUND = true;
            found_at = index;
            parent = item;
        }
    }
    if(TYPEFOUND)
    {
        int items = parent->childCount();
        bool NOTINSERTED = true;
        int i = 0;
        QTreeWidgetItem * child = new QTreeWidgetItem(found_at);
        child->setText(0,fileinfo.mFilename);
        while(NOTINSERTED)
        {
            if(fileinfo.mFilename.compare(parent->child(i)->text(0)) >= 0)
            {
                parent->insertChild(i,child);
                NOTINSERTED = false;
            }
            else
            {
                i ++;
                if(i == items)
                {
                    parent->insertChild(i,child);
                    NOTINSERTED = false;
                }
            }
        }
    }
    else
    {
        QTreeWidgetItem * parent = new QTreeWidgetItem(ui->TreeWidget->topLevelItemCount());
        parent->setText(0,fileinfo.mType);
        ui->TreeWidget->addTopLevelItem(parent);
        QTreeWidgetItem * child = new QTreeWidgetItem(0);
        child->setText(0,fileinfo.mFilename);
        parent->insertChild(0,child);
    }
}

void ProjectExplorer::createEmptyProject()
{

    QTreeWidgetItem * codeptr = new QTreeWidgetItem(0);
    QTreeWidgetItem * otherptr = new QTreeWidgetItem(1);
    codeptr->setText(0,"Code");
    otherptr->setText(0,"Other");
    QIcon icon(":/images/images/Open.png");
    codeptr->setIcon(0,icon);
    otherptr->setIcon(0,icon);
    ui->TreeWidget->addTopLevelItem(codeptr);
    ui->TreeWidget->addTopLevelItem(otherptr);


}

void ProjectExplorer::openProject(ProjectFile * project_file)
{
}


void ProjectExplorer::setCurrentProject(int index)
{


}

ProjectExplorer::~ProjectExplorer()

{
    delete ui;
}
