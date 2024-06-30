#include "user_register.h"
#include "ui_user_register.h"
#include "user_login.h"
#include "database.h"
#include "user_register_success.h"
User_register::User_register(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User_register)
{
    ui->setupUi(this);
    setWindowTitle("注册");
    // 设置窗口大小为400x300
    setFixedSize(400, 300);
    // 创建一个 QPalette 对象
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/pic10.png");
    pixmap = pixmap.scaled(400, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    palette.setBrush(QPalette::Window, pixmap);
    // 设置窗口的调色板
    this->setPalette(palette);
}

User_register::~User_register()
{
    delete ui;
}

void User_register::on_pushButton_2_clicked()
{
    User_login*u=new User_login;
    close();
    u->show();
}


void User_register::on_pushButton_clicked()
{
    QString user_name1=ui->lineEdit->text();
    QString user_password1=ui->lineEdit_2->text();
    if(user_name1!=""&&user_password1!=""){
        Database::registerUser(user_name1,user_password1);
        User_register_success* u=new User_register_success;
        u->show();
        close();
    }
    else{
        ui->label_4->setText("请输入注册的账号和密码！");
    }
}

