#ifndef KEYWORDLIST_H
#define KEYWORDLIST_H
#include <QString>
#include <QList>
#include <QStringList>
#include <QPair>
struct KeywordList
{
   QStringList mKeyWords;
   QString mName;
   QString mStyle;
   QList< QPair< int, bool> > mFlags; // int = flag type bool = on/off
};

#endif // KEYWORDLIST_H
