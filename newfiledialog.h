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
public slots:
    void createFile();
    void findDirectory();
};

#endif // NEWFILEDIALOG_H
