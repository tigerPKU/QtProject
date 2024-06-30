#include "user_register_success.h"
#include "ui_user_register_success.h"
#include "user_login.h"
User_register_success::User_register_success(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User_register_success)
{
    ui->setupUi(this);
    setWindowTitle("提示");
}

User_register_success::~User_register_success()
{
    delete ui;
}

void User_register_success::on_pushButton_clicked()
{
    User_login* u=new User_login;
    u->show();
    close();
}

