#include "aide.h"
#include "projectexplorer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aide w;
    ProjectExplorer * pExplorer = new ProjectExplorer(&w);
    w.addDockWidget(Qt::LeftDockWidgetArea,pExplorer,Qt::Vertical);
    w.show();

    return a.exec();
    delete pExplorer;

}
