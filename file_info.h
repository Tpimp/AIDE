#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <QString>
#include <QList>

struct FileInfo
{
    // Data Members
    QString mFilename;
    QString mDir;
    QString mPath;
    QString mType;
    QList<int> mBreakpoints;
};



#endif // FILE_INFO_H
