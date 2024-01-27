#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "dialogadd.h"
#include "filehandler.h"
#include "dialogcountryimport.h"
#include "dialogproductimport.h"
#include "dialogschedule.h"
#include <QMap>
#include <QVector>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void showRow(int i,recProd r);
public slots:
    void updateTable();
private slots:
    void on_pushButtonDelete_clicked();

    void on_buttonCountryImport_clicked();

    void on_buttonCountryExport_clicked();

    void on_buttonProductImport_clicked();

    void on_button4_clicked();

private:
    Ui::Dialog *ui;
    DialogAdd *dialogAdd;
    DialogCountryImport *dialogCountryImport;
    DialogProductImport *dialogProductImport;
    DialogSchedule *dialogSchedule;
};
#endif // DIALOG_H
