#ifndef AIDE_H
#define AIDE_H

#include <QMainWindow>
#include <newfiledialog.h>
#include <QList>
#include <projectfile.h>

namespace Ui
{
    class Aide;
}

class Aide : public QMainWindow
{
        Q_OBJECT

    public:
        explicit Aide(QWidget *parent = 0);
        ~Aide();

    private:
        Ui::Aide *ui;
        NewFileDialog * m_NewFileDialog;
        QList<ProjectFile *> m_OpenProjects;
};

#endif // AIDE_H
