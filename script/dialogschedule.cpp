#include "dialogschedule.h"
#include "ui_dialogschedule.h"
#include "filehandler.h"
#include <QPainter>
DialogSchedule::DialogSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogSchedule)
{
    ui->setupUi(this);
    scene=new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addLine(20,380,480,380);
    scene->addLine(20,380,20,20);
    scene->addEllipse(22,387,5,8);
    for (size_t i=66;i<480;i+=46){
        scene->addLine(i,385,i,375);
    }
    for (size_t i=56;i<380;i+=36){
        scene->addLine(15,i,25,i);
    }
    connect(ui->btnExit, SIGNAL(clicked(bool)),
            this,SLOT(close()));
}

DialogSchedule::~DialogSchedule()
{
    delete ui;
}

void DialogSchedule::on_btnInf_clicked()
{
    QPen pen;
    pen.setColor(Qt:: red);
    pen.setWidth(3);
    QPolygon pol;
    FileHandler fileHandler;
    QMap<QString,int> ProductExport;
    while (fileHandler.readRec()){
        if ((fileHandler.r.name==ui->leSchedule->text())and(fileHandler.r.direction=="Export")){
            ProductExport[fileHandler.r.year]+=fileHandler.r.volume.toInt();
        }
    }
    QMap<QString, int>::const_iterator i = ProductExport.constBegin();
    int x1=(i.key().toInt()-2010)*46-20;
    int y1=i.value()*3.6+20;
    int x2=x1,y2=y1;
    while (i != ProductExport.constEnd()) {
        pol<<QPoint((i.key().toInt()-2010)*46-20,i.value()*3.6+20);
        x2=(i.key().toInt()-2010)*46-20;
        y2=i.value()*3.6+20;
        ++i;
    }
    scene->addPolygon(pol,pen);
    pen.setColor(Qt:: white);
    scene->addLine(x1,y1,x2,y2,pen);
}
