#ifndef DIALOGPRODUCTIMPORT_H
#define DIALOGPRODUCTIMPORT_H

#include <QWidget>
#include "filehandler.h"
#include "ui_DialogProductImport.h"
namespace Ui {
class DialogProductImport;
}
class DialogProductImport : public QWidget
{
    Q_OBJECT
public:
    recProd r;
    explicit DialogProductImport(QWidget *parent = nullptr);
    ~DialogProductImport();
    Ui::DialogProductImport *ui;
signals:

private slots:
    void on_btnInf_clicked();
};

#endif // DIALOGPRODUCTIMPORT_H
