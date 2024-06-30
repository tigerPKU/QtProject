#include "rider_rigister_success.h"
#include "rider_login.h"
#include "ui_rider_rigister_success.h"
#include "database.h"

rider_rigister_success::rider_rigister_success(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rider_rigister_success)
{
    ui->setupUi(this);
    Database t;
    int x = t.getRiderCount();//接入数据 这块用引用
    ui->lcdNumber->display(x);
    setWindowTitle("提示");

}

rider_rigister_success::~rider_rigister_success()
{
    delete ui;
}

void rider_rigister_success::on_lcdNumber_overflow()
{

}


void rider_rigister_success::on_pushButton_clicked()
{
    close();
    rider_login *r = new rider_login;
    r->show();
}

