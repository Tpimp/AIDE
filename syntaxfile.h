#ifndef SYNTAXFILE_H
#define SYNTAXFILE_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QList>
#include <QStringList>
#include <QRegExp>
#include <QPair>
#include <QList>
#include <syntaxpattern.h>
#include <keywordlist.h>
class SyntaxFile
{

public:
    SyntaxFile(QString file);
    ~SyntaxFile();

private:
    QList<KeywordList> mKeywordLists;
    QChar mEscapeChar;
    QString mFile;
    QString mLanguage;
    QList<SyntaxPattern> mPatterns;

};

#endif // SYNTAXFILE_H
