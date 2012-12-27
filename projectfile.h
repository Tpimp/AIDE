#ifndef PROJECTFILE_H
#define PROJECTFILE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <file_info.h>
#include <QStringList>
#include <QString>
class ProjectFile : public QObject
{
    Q_OBJECT
public:
    explicit ProjectFile(QString name = "", QString FilePath = "",QObject *parent = 0);
    void addFile(FileInfo * file);
    void addFilter(QString filter);
    QList<FileInfo*> & Files(){return mFiles;}
    QStringList & Filters(){return mFilters;}
    QString filePath(){return mPath;}
    QString name(){return mName;}
    void loadProject(QString project_location);
    void saveProject();
    ~ProjectFile();

signals:
    
public slots:
    
private:
    QString mName;
    QString mPath;
    QList<FileInfo *> mFiles;
    QStringList mFilters;
};

#endif // PROJECTFILE_H
