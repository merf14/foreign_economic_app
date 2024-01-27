#include "dialog.h"
#include "./ui_dialog.h"
#include <QtWidgets>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    FileHandler fileHandler;
    ui->setupUi(this);
    dialogAdd=new DialogAdd();
    dialogCountryImport=new DialogCountryImport();
    dialogProductImport=new DialogProductImport();
    dialogSchedule=new DialogSchedule();
    connect(ui->buttonAdd, SIGNAL(clicked(bool)),dialogAdd,SLOT(show()));
    connect(ui->buttonExit, SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(dialogAdd,SIGNAL(updateFile()),this,SLOT(updateTable()));
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::updateTable(){
    FileHandler fileHandler;
    int i=0;
    while (fileHandler.readRec()){
        ui->table->setRowCount(i+1);
        showRow(i,fileHandler.r);
        ++i;
    }

}
void Dialog::showRow(int i,recProd r)
{
    QTableWidgetItem *item;
    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(QString::number(i+1));
    ui->table->setItem(i,0,item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(r.name);
    ui->table->setItem(i,1,item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(r.volume);
    ui->table->setItem(i,2,item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(r.year);
    ui->table->setItem(i,3,item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(r.country);
    ui->table->setItem(i,4,item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(r.direction);
    ui->table->setItem(i,5,item);
}

void Dialog::on_pushButtonDelete_clicked()
{
    FileHandler fileHandler;
    QVector<recProd> a;
    while (fileHandler.readRec()){
        a.push_back(fileHandler.r);
    }
    fileHandler.deleteElement(a);
    updateTable();
}


void Dialog::on_buttonCountryImport_clicked()
{
    dialogCountryImport->show();
}



void Dialog::on_buttonCountryExport_clicked()
{
    FileHandler fileHandler;
    int maxVolume=0;
    QString maxCountry;
    QMap<QString,int> CountryExport;
    while (fileHandler.readRec()){
        if (fileHandler.r.direction=="Export"){
            CountryExport[fileHandler.r.country]+=fileHandler.r.volume.toInt();
        }
    }
    QMap<QString, int>::const_iterator i = CountryExport.constBegin();
    while (i != CountryExport.constEnd()) {
        if (i.value()>maxVolume) {
            maxCountry=i.key();
            maxVolume=i.value();
        }
        ++i;
    }
    ui->labelCountryExport->setText(maxCountry);
}


void Dialog::on_buttonProductImport_clicked()
{
   dialogProductImport->show();
}


void Dialog::on_button4_clicked()
{
    dialogSchedule->show();
}

