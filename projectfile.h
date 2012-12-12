#ifndef PROJECTFILE_H
#define PROJECTFILE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <file_info.h>
#include <QStringList>
class ProjectFile : public QObject
{
    Q_OBJECT
public:
    explicit ProjectFile(QString FilePath = "",QObject *parent = 0);
    bool addFile(FileInfo * file);
    ~ProjectFile();
signals:
    
public slots:
    
private:
    QFile * mFile;
    QString mName;
    QString mPath;
    QXmlStreamReader * mReader;
    QXmlStreamWriter * mWriter;
    QList<FileInfo *>    mFiles;
    QStringList      mFilters;
};

#endif // PROJECTFILE_H
