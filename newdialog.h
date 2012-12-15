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


public slots:
    void create();
    void selectProject();
    void selectFile();
    void setDescription();
};

#endif // NEWDIALOG_H
