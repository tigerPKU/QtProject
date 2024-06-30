#include "user_login.h"
#include "mainwindow.h"
#include "ui_user_login.h"
#include "yonghu.h"
#include "current_user.h"
#include "database.h"
#include "user_register.h"
User_login::User_login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User_login)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    // 设置窗口大小为400x300
    setFixedSize(400, 300);
    // 创建一个 QPalette 对象
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/pic9.png");
    pixmap = pixmap.scaled(400, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    palette.setBrush(QPalette::Window, pixmap);
    // 设置窗口的调色板
    this->setPalette(palette);
}

User_login::~User_login()
{
    delete ui;
}

void User_login::on_pushButton_clicked()
{
    QString user_name1=ui->lineEdit->text();
    QString user_password1=ui->lineEdit_2->text();
    //read();
    if(Database::loginUser(user_name1,user_password1)){
        Current_username=user_name1;
        yonghu* y=new yonghu;
        y->show();
        close();
    }
    else{
        ui->label_5->setText("账号或密码错误!");
    }
}


void User_login::on_pushButton_2_clicked()
{
    User_register* u=new User_register;
    u->show();
    close();
}


void User_login::on_pushButton_3_clicked()
{
    close();
    MainWindow* m = new MainWindow;
    m->show();
}

