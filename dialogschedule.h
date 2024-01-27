#ifndef DIALOGSCHEDULE_H
#define DIALOGSCHEDULE_H

#include <QWidget>
#include <QGraphicsScene>
#include "filehandler.h"
#include "ui_dialogschedule.h"
namespace Ui {
class DialogSchedule;
}
class DialogSchedule : public QWidget
{
    Q_OBJECT
public:
    recProd r;
    explicit DialogSchedule(QWidget *parent = nullptr);
    ~DialogSchedule();
    Ui::DialogSchedule *ui;
private:
    QGraphicsScene *scene;
private slots:
    void on_btnInf_clicked();
};

#endif // DIALOGSCHEDULE_H
