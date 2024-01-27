#ifndef DIALOGCOUNTYIMPORT_H
#define DIALOGCOUNTYIMPORT_H

#include <QWidget>
#include "filehandler.h"
#include "ui_DialogCountryImport.h"
namespace Ui {
class DialogCountryImport;
}
class DialogCountryImport : public QWidget
{
    Q_OBJECT
public:
    recProd r;
    explicit DialogCountryImport(QWidget *parent = nullptr);
    ~DialogCountryImport();
    Ui::DialogCountryImport *ui;
signals:

private slots:
    void on_btnInf_clicked();
};

#endif // DIALOGCOUNTrYIMPORT_H
