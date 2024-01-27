#include "dialogproductimport.h"
#include "ui_DialogProductImport.h"
#include "filehandler.h"
DialogProductImport::DialogProductImport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogProductImport)
{
    ui->setupUi(this);
    connect(ui->btnExit, SIGNAL(clicked(bool)),
            this,SLOT(close()));
}

DialogProductImport::~DialogProductImport()
{
    delete ui;
}

void DialogProductImport::on_btnInf_clicked()
{
    FileHandler fileHandler;
    QMap<QString,int> ProductImport;
    ui->labelCountry->setText("Countries:\n");
    ui->labelVolume->setText("Volume:\n");
    while (fileHandler.readRec()){
        if ((fileHandler.r.name==ui->leProductImport->text())and(fileHandler.r.direction=="Import")){
            ProductImport[fileHandler.r.country]+=fileHandler.r.volume.toInt();
        }
    }
    QMap<QString, int>::const_iterator i = ProductImport.constBegin();
    while (i != ProductImport.constEnd()) {
        ui->labelCountry->setText(ui->labelCountry->text()+i.key()+"\n");
        ui->labelVolume->setText(ui->labelVolume->text()+QString::number(i.value())+"\n");
        ++i;
    }
}
