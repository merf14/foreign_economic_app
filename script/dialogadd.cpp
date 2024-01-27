#include "dialogadd.h"
#include "ui_dialogadd.h"
#include "filehandler.h"
DialogAdd::DialogAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
    connect(ui->btnAdd, SIGNAL(clicked(bool)),
           this,SLOT(addRecord()));
    connect(ui->btnExit, SIGNAL(clicked(bool)),
            this,SLOT(close()));
}

DialogAdd::~DialogAdd()
{
    delete ui;
}

void DialogAdd::addRecord()
{
    FileHandler fileHandler;
    recProd r;
    r.name=ui->leName->text();
    r.volume=ui->leVolume->text();
    r.year=ui->leYear->text();
    r.country=ui->leCountry->text();
    r.direction=ui->leDirection->text();
    ui->leName->clear();
    ui->leVolume->clear();
    ui->leYear->clear();
    ui->leCountry->clear();
    ui->leDirection->clear();
    fileHandler.addElement(r);
    emit updateFile();
}

