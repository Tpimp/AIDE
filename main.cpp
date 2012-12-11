#include "aide.h"
#include "projectexplorer.h"
#include "editor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aide w;
    ProjectExplorer * pExplorer = new ProjectExplorer(&w);
    Editor * editor = new Editor();
    w.addDockWidget(Qt::LeftDockWidgetArea,pExplorer,Qt::Vertical);
    w.setCentralWidget(editor);
    w.show();

    return a.exec();
    delete pExplorer;
    delete editor;

}
