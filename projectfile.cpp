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
   writer.writeStartElement("Filters");
   foreach( QString filter, mFilters)
   {
      writer.writeTextElement("Filter",filter);
   }
   writer.writeEndElement();
   writer.writeStartElement("Files");
   foreach( FileInfo * file, mFiles)
   {
       writer.writeStartElement("File");
       writer.writeTextElement("Name", file->mFilename);
       writer.writeTextElement("FilePath", file->mPath);
       writer.writeTextElement("Type", file->mType);
       if(file->mBreakpoints.size() > 0)
       {
           writer.writeStartElement("Breakpoints");
           foreach(int  line_count, file->mBreakpoints)
           {
               writer.writeTextElement("Breakpoint",QString::number(line_count));
           }
           writer.writeEndElement();
       }
       writer.writeEndElement();
   }
   writer.writeEndElement();
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
