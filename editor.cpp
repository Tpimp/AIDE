#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    ui->TabWidget->setDocumentMode(true);
    /*needs a language parameter to pass
    to the highlighter constructor based on
    which file type we are editing for*/
    //mHighlighter = new Highlighter(this.language, this);
    mHighlighter = new Highlighter(ui->TextEdit->document());
}



Editor::~Editor()
{
    delete ui;
}
