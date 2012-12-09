#include "aide.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aide w;
    w.show();
    
    return a.exec();
}
