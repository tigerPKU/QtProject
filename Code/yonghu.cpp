#include "yonghu.h"
#include "ui_yonghu.h"
#include "help_me_take.h"
#include "order_page.h"
#include "help_me_buy.h"
#include "user_login.h"
yonghu::yonghu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::yonghu)
{
    ui->setupUi(this);
    setWindowTitle("用户端");
}

yonghu::~yonghu()
{
    delete ui;
}

void yonghu::on_pushButton_clicked()
{
    close();
    help_me_take* ui=new help_me_take;
    ui->show();
}


void yonghu::on_pushButton_6_clicked()
{
    Order_Page* ui1=new Order_Page;
    close();
    ui1->show();
}


void yonghu::on_pushButton_2_clicked()
{
    close();
    Help_me_buy* ui=new Help_me_buy;
    ui->show();
}


void yonghu::on_pushButton_7_clicked()
{
    User_login* u = new User_login;
    close();
    u->show();
}

