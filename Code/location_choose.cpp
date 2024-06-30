#include "location_choose.h"
#include "ui_location_choose.h"
#include "qpixmap.h"
#include <QDebug>
#include <QMouseEvent>
#include "Position.h"
#include "help_me_buy.h"
#include "help_me_take.h"
#include "rider.h"
#include "message_view2.h"
#include <cmath> // 包含数学函数，用于计算距离
Location_choose::Location_choose(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Location_choose)
{
    ui->setupUi(this);
    QPixmap pixmap(":/new/prefix1/map.png");
    QSize labelSize = ui->label->size();
    // 将 QPixmap 按照 QLabel 的尺寸等比例缩放
    QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(scaledPixmap);
    setWindowTitle("选择地图");
}
Location_choose::Location_choose(int typee,int detaill):type(typee),detail(detaill), ui(new Ui::Location_choose)
{
    ui->setupUi(this);
    QPixmap pixmap(":/new/prefix1/map.png");
    QSize labelSize = ui->label->size();
    // 将 QPixmap 按照 QLabel 的尺寸等比例缩放
    QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(scaledPixmap);

}
double Location_choose::manhattanDistance(const QPoint &p1, const QPoint &p2) const
{
    return qFabs(p1.x() - p2.x()) + qFabs(p1.y() - p2.y());
}

Location_choose::~Location_choose()
{
    delete ui;
}
void Location_choose::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint clickPos = event->pos();
        qDebug() << "Mouse clicked at:" << clickPos;
        ui->label_3->setText(Location_choose::findNearestString(clickPos));
        QString ns=findNearestString(clickPos);
        Chosen_name=ns;
        for(int i=0;i<15;i++){
            if(ns==Names[i]){
                Chosen_point=Addresses[i];
            }
        }
        emit mouseClicked(clickPos);
    }
}
// void Location_choose::addMapping(const QPoint &point, const QString &text)
// {
//     pointToStringMap[point] = text;
// }

QString Location_choose::findNearestString(const QPoint &point) const
{

    // 初始化最小距离和对应的QString
    double mind=10000000;
    int rem=0;
    for(int i=0;i<15;i++){
        if(mind>Location_choose::manhattanDistance(Addresses[i],point)){
            mind=manhattanDistance(Addresses[i],point);
            rem=i;
        }
    }
    QString nearestString=Names[rem];
    // Chosen_point=Addresses[rem];
    return nearestString;
}

void Location_choose::on_pushButton_clicked()
{
    if(type==1){
        if(detail==1){
            Help_me_buy::m.address_from=Chosen_name;
            Help_me_buy::m.x_start=Chosen_point.x();
            Help_me_buy::m.y_start=Chosen_point.y();
        }
        else if(detail==2){
            Help_me_buy::m.address_to=Chosen_name;
            Help_me_buy::m.x_end=Chosen_point.x();
            Help_me_buy::m.y_end=Chosen_point.y();
        }

    }
    else if(type==2){
        if(detail==1){
            help_me_take::m.address_from=Chosen_name;
            help_me_take::m.x_start=Chosen_point.x();
            help_me_take::m.y_start=Chosen_point.y();
        }
        else if(detail==2){
            help_me_take::m.address_to=Chosen_name;
            help_me_take::m.x_end=Chosen_point.x();
            help_me_take::m.y_end=Chosen_point.y();
        }
    }
    else if(type==3){
        rider::Current_loc=Chosen_name;
        rider::Current_point=Chosen_point;

    }
    close();
}

