#include <QtGui/QApplication>
#include "buildsystem.h"
#include <QString>
#include <QStringList>

int main(int argc, char *argv[])
{
    bool GUI(false);

    if(argc > 1)
    {
        QString arg1 = argv[1];
        //this will eventually check
        //arg1 against a case table
        //containing "Debug" "Build" "Run" "Clean" etc...
        //determine more as needed
        if (arg1 == "Debug")
            GUI = true;
    }

    //QApplication receives GUI flag to enable/disable
    QApplication a(argc, argv, GUI);
    //BuildSystem receives GUI flag to know when to draw the GUI
    BuildSystem b(a.arguments(), GUI);


    return a.exec();
}
