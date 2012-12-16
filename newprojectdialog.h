#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QString>
namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

private:
    Ui::NewProjectDialog *ui;
signals:
    void projectAdded(QString filepath);

public slots:
    void createProject();
    //void checkPath(QString path);
    void findDirectory();
    void setName(QString newName);
};

#endif // NEWPROJECTDIALOG_H
