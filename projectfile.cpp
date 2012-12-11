#include "projectfile.h"

ProjectFile::ProjectFile(QString filePath,QObject *parent) :
    QObject(parent), mFile(0), mWriter(0), mReader(0)
{

}

ProjectFile::~ProjectFile()
{

}
