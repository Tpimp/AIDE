#include <QtGui/QApplication>
#include <QCoreApplication>
#include "buildsystem.h"
#include <QString>
#include <QStringList>

enum BuildSystemMode {RUN = 0, DEBUG,
                      REBUILD, CLEAN}; //add as needed

int main(int argc, char *argv[])
{
    bool GUI(false);
    BuildSystemMode run_time_type;

    QString build_enum_param = argv[1];

    if (argc > 1)
    {

        if (build_enum_param == "Run")
            run_time_type = RUN;
        else if (build_enum_param == "Debug")
            run_time_type = DEBUG;
        else if (build_enum_param == "Rebuild")
            run_time_type = REBUILD;
        else if (build_enum_param == "Clean")
            run_time_type = CLEAN;
    }

    if (run_time_type == DEBUG)
        GUI = true;

    //QApplication receives GUI flag to enable/disable
    QApplication a(argc, argv, GUI);
    //BuildSystem receives GUI flag to know when to draw the GUI
    BuildSystem b(a.arguments(), GUI);


    return a.exec();
}
