#ifndef SYNTAXPATTERN_H
#define SYNTAXPATTERN_H
#include <QString>
#include <QList>
#include <QRegExp>
#include <QPair>
struct SyntaxPattern
{
  QString mName;
  QList<QRegExp> mPattern;
  QString mStyle;
  QList< QPair< int, bool> > mFlags; // int = flag type bool = on/off
};


#endif // SYNTAXPATTERN_H
