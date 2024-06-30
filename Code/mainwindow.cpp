#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rider.h"
#include "rider_login.h"
#include "ui_yonghu.h"
#include "yonghu.h"
#include "user_login.h"
#include "location_choose.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("北大跑男团");
    // ui->label->setStyleSheet("QLabel { color: red; }");
    // 设置窗口大小为400x300
    setFixedSize(400, 300);
    // 创建一个 QPalette 对象
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/pic11.png");
    pixmap = pixmap.scaled(400, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    palette.setBrush(QPalette::Window, pixmap);
    // 设置窗口的调色板
    this->setPalette(palette);


    // 使用样式表设置背景图片，并确保背景图片适应窗口大小
    // this->setStyleSheet("QMainWindow { background-image: url(:/new/prefix1/pic2.png); background-position: center; background-repeat: no-repeat; background-size: cover; }");
     // this->setStyleSheet("QMainWindow { background-image: url(:/new/prefix1/pic2.png); background-position: center; background-repeat: no-repeat; background-size: cover;}");
    // this->setStyleSheet("QWidget { background-image: url(qrc:/new/prefix1/pic2.png); background-position: center; background-repeat: no-repeat; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(1){//确认函数
        close();
        User_login* ui1=new User_login;
        ui1->show();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    rider_login* r = new rider_login;
    close();
    r->show();
}




