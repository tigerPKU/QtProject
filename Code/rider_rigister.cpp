#include "rider_rigister.h"
#include "rider_login.h"
#include "rider_rigister_success.h"
#include "ui_rider_rigister.h"
#include "database.h"

rider_rigister::rider_rigister(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rider_rigister)
{
    ui->setupUi(this);
    Database t;
    int x = t.getRiderCount();//接入数据
    ui->lcdNumber->display(x);
    setWindowTitle("注册");
    // 设置窗口大小为400x300
    setFixedSize(400, 300);
    // 创建一个 QPalette 对象
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/pic8.png");
    pixmap = pixmap.scaled(400, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    palette.setBrush(QPalette::Window, pixmap);
    // 设置窗口的调色板
    this->setPalette(palette);

}

rider_rigister::~rider_rigister()
{
    delete ui;
}

void rider_rigister::on_lcdNumber_overflow()
{

}


void rider_rigister::on_pushButton_clicked()
{
    bool x = 1;
    if(x == 1)
    {
        Database t;
        t.registerRider(ui->lineEdit->text(), ui->lineEdit_2->text());
        close();
        rider_rigister_success* r = new rider_rigister_success;
        r->show();

    }
    else
    {
        ui->label_5->setText("用户名或密码不合法");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

    }
}


void rider_rigister::on_pushButton_2_clicked()
{
    close();
    rider_login* r = new rider_login;
    r->show();
};

