#ifndef NEWDIALOG_H
#define NEWDIALOG_H
#include <QTreeWidgetItem>
#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewDialog(QWidget *parent = 0);
    ~NewDialog();


private:
    Ui::NewDialog *ui;

signals:
    void newFileCreated(QString filepath);

public slots:
    void create();
    void selectProject();
    void selectFile();
    void setDescription(QTreeWidgetItem* current,QTreeWidgetItem* previous);
};

#endif // NEWDIALOG_H
