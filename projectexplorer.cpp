#include "projectexplorer.h"
#include "ui_projectexplorer.h"
#include <QTreeWidgetItem>
#include <QDir>
#include <QFileInfo>
#include <aide.h>
ProjectExplorer::ProjectExplorer(QWidget *parent) :
    QDockWidget(parent), ui(new Ui::ProjectExplorer),mCurrentProject(0), mFilterIcon(":/images/images/Open.png")
{

    ui->setupUi(this);
    setGeometry(0,0,260,1080);
    setStyleSheet(
                     "QDockWidget::title{ position: absolute; padding-left: 3px;text-align: center; background-color: blue; border: 2px solid black; }"
                     "QDockWidget { color: yellow; font bold 20px; border: 2px solid black; }"
                 );  // set the dock widget title style
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea); // Set this dock widget for only left and ride sides
    mProjectMenu = new QMenu("ProjectMenu",ui->TreeWidget);
    QAction * new_file = mProjectMenu->addAction("Add New File");
    QAction * add_file = mProjectMenu->addAction("Add Existing File");
    connect(ui->TreeWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(openContextMenu(QPoint)));
}

FileInfo ProjectExplorer::addFile(QString filepath, QString type)
{
    QFileInfo info(filepath);
    FileInfo fileinfo;
    fileinfo.mRelativePath = fileinfo.mPath = info.absolutePath();
    fileinfo.mDir = info.dir().dirName();
    fileinfo.mFilename = info.completeBaseName() + '.' + info.completeSuffix();
    fileinfo.mType = type;
    QString project_path = ((Aide*)this->parent())->getProject(mCurrentProject)->filePath();
    fileinfo.mRelativePath.remove(/*project_path*/ "/home/christopher/Qt_Projects/AIDE-build-Desktop-Debug");
    int filters = ui->TreeWidget->topLevelItemCount();
    QTreeWidgetItem * child;
    bool TYPEFOUND = false;
    int found_at = 0;
    QTreeWidgetItem * parent = 0;
    for (int index = 0; index < filters; index ++)
    {
        QTreeWidgetItem * item = ui->TreeWidget->topLevelItem(index);
        if(item)
        {
            if(type == item->text(0))
            {
                TYPEFOUND = true;
                found_at = index;
                parent = item;
            }
        }

    }
    if(TYPEFOUND)
    {
        int items = parent->childCount();
        bool NOTINSERTED = true;
        int i = 0;
        child = new QTreeWidgetItem(found_at);
        child->setText(0,fileinfo.mFilename);
        if(items > 0)
        {
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
            parent->insertChild(0,child);
        }

    }
    else
    {
        QTreeWidgetItem * parent = new QTreeWidgetItem(ui->TreeWidget->topLevelItemCount());
        parent->setText(0,fileinfo.mType);
        parent->setIcon(0,mFilterIcon);
        ui->TreeWidget->addTopLevelItem(parent);
        child = new QTreeWidgetItem(0);
        child->setText(0,fileinfo.mFilename);
        parent->insertChild(0,child);
    }
    QString iconpath = getIcon(fileinfo);
    QPixmap  icon(QDir::currentPath()+iconpath);
    child->setIcon(0,icon);
    return fileinfo;
}

void ProjectExplorer::addFilter(QString filter)
{
    QTreeWidgetItem * treewidgetitem = new QTreeWidgetItem(ui->TreeWidget->topLevelItemCount()-1);
    treewidgetitem->setText(0,filter);
    treewidgetitem->setIcon(0,mFilterIcon);
    ui->TreeWidget->addTopLevelItem(treewidgetitem);
}

void ProjectExplorer::addProject(QString name)
{
    ui->ProjectSelector->addItem(name);
    mCurrentProject = ui->ProjectSelector->count()-1;
    ui->ProjectSelector->setCurrentIndex(mCurrentProject);
}

void ProjectExplorer::createEmptyProject()
{

    QTreeWidgetItem * codeptr = new QTreeWidgetItem(0);
    QTreeWidgetItem * otherptr = new QTreeWidgetItem(1);
    codeptr->setText(0,"Code");
    otherptr->setText(0,"Other");
    codeptr->setIcon(0,mFilterIcon);
    otherptr->setIcon(0,mFilterIcon);
    ui->TreeWidget->addTopLevelItem(codeptr);
    ui->TreeWidget->addTopLevelItem(otherptr);
}

void ProjectExplorer::fillTreeWidget(ProjectFile *project)
{
    QStringList & filters = project->Filters();
    foreach(QString filter, filters)
    {
       addFilter(filter);
    }
    QList<FileInfo *> & files = project->Files();
    foreach(FileInfo * file, files)
    {
        addFile((file->mPath+file->mFilename),file->mType);
    }
}

QString ProjectExplorer::getIcon(FileInfo fileinfo)
{
    QString extension = fileinfo.mFilename.remove(0,fileinfo.mFilename.lastIndexOf(".")+1);
    extension = extension.toLower();
    extension += ".png";
    return ("/images/files/" + extension);
}

void ProjectExplorer::openContextMenu(QPoint pos)
{
    mProjectMenu->popup(ui->TreeWidget->mapToGlobal(pos));
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
    delete mProjectMenu;
}
