#ifndef DIALOGADD_H
#define DIALOGADD_H
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include "ui_dialogadd.h"
#include "filehandler.h"
namespace Ui {
class DialogAdd;
}

class DialogAdd : public QWidget
{
    Q_OBJECT
public:
    explicit DialogAdd(QWidget *parent = 0);
    ~DialogAdd();
signals:
    void updateFile();
public slots:
    void addRecord();
private slots:
private:
    Ui::DialogAdd *ui;

};

#endif // DIALOGADD_H
