#include "projectfile.h"

ProjectFile::ProjectFile(QString filePath,QObject *parent) :
    QObject(parent), mFile(0), mWriter(0), mReader(0), mName(""), mPath("")
{
    mFilters.append(QString("Code"));
    mFilters.append(QString("Other"));

}
bool ProjectFile::addFile(FileInfo * file)
{
   mFiles.append(file);
}

ProjectFile::~ProjectFile()
{
    mFile = 0;
    mWriter = 0;
    mReader = 0;
    mName.clear();
    mPath.clear();
    mFilters.clear();
    int count = mFiles.count();
    for (int index = 0; index < count; index ++)
    {
        FileInfo * ptr = mFiles.at(index);
        delete ptr;
    }
    mFiles.clear();
}
