#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QWidget>

#include <QFile>
#include <QDataStream>
#include <QVector>
#include <QString>
struct recProd{
    QString name,volume,year,country,direction;
};
class FileHandler : public QWidget
{
    Q_OBJECT

public:
    recProd r;
    explicit FileHandler(QWidget *parent = nullptr);
    ~FileHandler();   
    void addElement(recProd r);
    bool readRec();
    void deleteElement(QVector<recProd> a);
    //QVector<QString> seekCountryImport(QString country);
private:
   QFile *file;
};

#endif // FILEHANDLER_H
