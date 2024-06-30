#include "mainwindow.h"
#include "rider.h"
#include "rider_login.h"
#include "rider_rigister.h"
#include "ui_rider_login.h"
#include "database.h"

rider_login::rider_login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rider_login)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    // 设置窗口大小为400x300
    setFixedSize(400, 300);
    // 创建一个 QPalette 对象
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/pic7.png");
    pixmap = pixmap.scaled(400, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    palette.setBrush(QPalette::Window, pixmap);
    // 设置窗口的调色板
    this->setPalette(palette);
}

rider_login::~rider_login()
{
    delete ui;
}

void rider_login::on_pushButton_clicked()
{
    Database t;
    bool x = t.loginRider(ui->lineEdit->text(), ui->lineEdit_2->text());
    if(x == true)
    {
        close();
        rider *r = new rider(ui->lineEdit->text());
        r->show();
    }
    else
    {
        ui->label_4->setText("用户名或密码错误");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
}


void rider_login::on_pushButton_2_clicked()
{
    close();
    MainWindow* m = new MainWindow;
    m->show();
}


void rider_login::on_pushButton_3_clicked()
{
    close();
    rider_rigister* r = new rider_rigister;
    r->show();

}

