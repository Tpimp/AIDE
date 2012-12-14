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
    void addFile(FileInfo * file);
    ~ProjectFile();
signals:
    
public slots:
    
private:
    QString mName;
    QString mPath;
    QList<FileInfo *>    mFiles;
    QStringList      mFilters;
};

#endif // PROJECTFILE_H
