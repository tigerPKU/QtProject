#include "rider.h"
#include "message_view.h"
#include "message_view2.h"
#include "rider_login.h"
#include "ui_rider.h"
#include "location_choose.h"
#include "database.h"
QString rider::Current_loc=QString();
QPoint rider::Current_point=QPoint();
rider::rider(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rider)
{
    ui->setupUi(this);
    setWindowTitle("骑手端");
}
rider::rider(QString id1,QString loc1, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rider)
    , id(id1)
{
    ui->setupUi(this);
    ui->label_2->setText(id);
    // ui->label_5->setText(loc1);
    // ui->label_5->close();
    setWindowTitle("骑手端");
}

rider::~rider()
{
    delete ui;
}

void rider::on_pushButton_3_clicked()
{
    close();
    rider_login* r = new rider_login;
    r->show();

}


void rider::on_pushButton_clicked()
{
    close();
    message_view* m = new message_view(this->id);
    m->show();
}


void rider::on_pushButton_2_clicked()
{
    message_view2* m = new message_view2(id,Current_loc);
    // ui->label_5->show();
    // ui->label_5->setText(Current_loc);
    close();
    m->show();
}


void rider::on_pushButton_4_clicked()
{
    Location_choose* loc=new Location_choose(3,0);
    Database t;
    bool x=t.updateRiderLocation(id,Current_point.x(),Current_point.y());
    loc->show();
}

