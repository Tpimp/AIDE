#include <QtGui>
#include "highlighter.h"
#include "syntaxpattern.h"
#include "keywordlist.h"
Highlighter::Highlighter(/*QList language, */QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    mKeywordFormat.setForeground(Qt::blue);
    mKeywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;  

    keywordPatterns << "\\bpush\\b" << "\\bpop\\b";
    foreach (const QString &pattern, keywordPatterns)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = mKeywordFormat;
        mHighlightingRules.append(rule);
    }
}

void Highlighter::highlightBlock(const QString &text)
{
    int index(0);
    int length(0);
    foreach (const HighlightingRule &rule, mHighlightingRules)
    {
        QRegExp expression(rule.pattern);
        index = expression.indexIn(text);
        while (index >= 0)
        {
            length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index+length);
        }
    }
    //setCurrentBlockState(0);
}
