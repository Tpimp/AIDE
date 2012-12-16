#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>

namespace Ui
{
    class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewFileDialog(QWidget *parent = 0);
    ~NewFileDialog();
    
private:
    Ui::NewFileDialog *ui;

signals:
    void fileAdded(QString);

public slots:
    void createFile();
    void findDirectory();
    //void checkPath(QString path);
    void setName(QString newName);
};

#endif // NEWFILEDIALOG_H
