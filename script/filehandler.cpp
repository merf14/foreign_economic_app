#include "filehandler.h"
#include <QVector>
FileHandler::FileHandler(QWidget *parent) :
    QWidget(parent)
{
    file=new QFile("C:/Users/o/Documents/bbb/data.txt");
    file->open(QFile::ReadWrite);
}

FileHandler::~FileHandler()
{
    file->close();
    delete file;
}

void FileHandler::addElement(recProd prod){
    file->seek(file->size());
    QDataStream out(file);
    out<<prod.name<<prod.volume<<prod.year<<prod.country<<prod.direction;
    file->flush();
}
bool FileHandler::readRec()
{
    QDataStream in(file);
    if (in.atEnd())return false;
    else
    {
        in>>r.name>>r.volume>>r.year>>r.country>>r.direction;
        return true;
    }
}
void FileHandler::deleteElement(QVector<recProd> a){
    file->resize(0);
    for (size_t i=0;i<a.size()-1;++i){
        addElement(a[i]);
    }
}





