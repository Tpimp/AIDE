#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <QString>
#include <QList>
#include <QPair>
struct FileInfo
{
    // Data Members
    QString mFilename;
    QString mDir;
    QString mPath;
    QString mType;
    QString mRelativePath;
    QList< int > mBreakpoints;
};



#endif // FILE_INFO_H
