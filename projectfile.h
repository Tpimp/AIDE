#ifndef PROJECTFILE_H
#define PROJECTFILE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>

class ProjectFile : public QObject
{
    Q_OBJECT
public:
    explicit ProjectFile(QString FilePath = "",QObject *parent = 0);
    ~ProjectFile();
signals:
    
public slots:
    
private:
    QFile * mFile;
    QXmlStreamReader * mReader;
    QXmlStreamWriter * mWriter;
};

#endif // PROJECTFILE_H
