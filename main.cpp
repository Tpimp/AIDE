#include "aide.h"
#include "projectexplorer.h"
#include "editor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aide aide;
    aide.show();

    return a.exec();

}
