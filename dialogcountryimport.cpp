#include "dialogcountryimport.h"
#include "ui_DialogCountryImport.h"
#include "filehandler.h"
DialogCountryImport::DialogCountryImport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogCountryImport)
{
    ui->setupUi(this);
    connect(ui->btnExit, SIGNAL(clicked(bool)),
            this,SLOT(close()));
}

DialogCountryImport::~DialogCountryImport()
{
    delete ui;
}

void DialogCountryImport::on_btnInf_clicked()
{
    FileHandler fileHandler;
    int s=0;
    ui->labelInf->setText("Products:\n");
    while (fileHandler.readRec()){
        if ((fileHandler.r.country==ui->leCountryImport->text())and(fileHandler.r.direction=="Import")){
            ui->labelInf->setText(ui->labelInf->text()+"\n"+fileHandler.r.name);
            s+=fileHandler.r.volume.toInt();
        }
    }
    ui->labelInf->setText(ui->labelInf->text()+"\nTotal volume: "+QString::number(s));
}

