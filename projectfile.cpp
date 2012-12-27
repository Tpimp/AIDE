#include "projectfile.h"

ProjectFile::ProjectFile(QString name, QString filePath,QObject *parent) :
    QObject(parent), mName(name), mPath(filePath)
{
    int slash = filePath.lastIndexOf("/");
    mPath = filePath.section("",0,slash+1);
    if(mName == "")
        mName = filePath.remove(slash,filePath.size());
}

void ProjectFile::addFile(FileInfo * file)
{
    mFiles.append(file);
}

void ProjectFile::addFilter(QString filter)
{
    mFilters.append(filter);
}

void ProjectFile::loadProject(QString project_location)
{

}

void ProjectFile::saveProject()
{
   QString data_out;
   QXmlStreamWriter writer(&data_out);
   writer.setAutoFormatting(true);
   writer.writeStartDocument();
   writer.writeStartElement("Project");
   writer.writeTextElement("Name",this->mName);
   writer.writeStartElement("Filters");
   foreach( QString filter, mFilters)
   {
      writer.writeTextElement("Filter",filter);
      foreach( FileInfo * file, mFiles)
      {
          if(file->mType == filter)
          {
              writer.writeStartElement("File");
              writer.writeTextElement("Name", file->mFilename);
              writer.writeTextElement("Path", file->mPath);
              writer.writeTextElement("Type", file->mType);
              if(file->mBreakpoints.size() > 0)
              {
                  writer.writeStartElement("Breakpoints");
                  foreach(int  line_count, file->mBreakpoints)
                  {
                      writer.writeTextElement("BP",QString::number(line_count));
                  }
                  writer.writeEndElement();
              }
              writer.writeEndElement();
          }
      }
   }
   writer.writeEndElement();
   writer.writeEndElement();
   writer.writeEndDocument();
   QString filepath = (mPath + mName);
   QFile out(filepath);
   out.open(QIODevice::WriteOnly);
   out.write(data_out.toAscii());
   out.flush();
   out.close();
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
