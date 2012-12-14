#include "projectfile.h"

ProjectFile::ProjectFile(QString filePath,QObject *parent) :
    QObject(parent), mName(""), mPath("")
{
    mFilters.append(QString("Code"));
    mFilters.append(QString("Other"));
    mFiles.clear();
    int slash = filePath.lastIndexOf("/");
    mName = filePath.section(filePath,slash);
    mPath = filePath.remove(slash,filePath.size());


}
void ProjectFile::addFile(FileInfo * file)
{
    mFiles.append(file);
}

ProjectFile::~ProjectFile()
{
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
