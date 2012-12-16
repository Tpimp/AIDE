#ifndef SYNTAXFILE_H
#define SYNTAXFILE_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QList>
#include <QStringList>
#include <QRegExp>
#include <QPair>
#include <QList>
class SyntaxFile
{

public:
    SyntaxFile(QString file);
    ~SyntaxFile();

private:
    QList<QStringList> mKeywords;
    QChar mEscapeChar;
    QString mFile;

};

#endif // SYNTAXFILE_H
