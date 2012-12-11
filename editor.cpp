#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    ui->TabWidget->setDocumentMode(true);
}



Editor::~Editor()
{
    delete ui;
}
