#include "message_view.h"
#include "rider.h"
#include "ui_message_view.h"
#include "database.h"
#include "ordermessage.h"
#include "cancel_success.h"
message_view::message_view(QString id1, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::message_view)
    , id(id1)
{
    /*
    QString ddl;
    QString address_from;
    QString address_to;
    double reward;
    QString requirements;
    int type_overall;//帮我取，帮我买，帮我送，帮我做，帮我寄
    int type_detail;//代取外卖，代取快递，自定义
    */


    ui->setupUi(this);
    ui->label_12->setText(this->id);
    setWindowTitle("我的订单");
    this->orders = new OrderMessage[50];
    this->displayPointer = 0;
    QSqlQuery query = Database::getOrdersByRidername(id);
    this->numOfOrders = 0;
    while (query.next()) {
        this->orders[numOfOrders].ddl = query.value("ddl").toString();
        this->orders[numOfOrders].address_from = query.value("address_from").toString();
        this->orders[numOfOrders].address_to = query.value("address_to").toString();
        this->orders[numOfOrders].reward = query.value("reward").toDouble();
        this->orders[numOfOrders].type_overall = query.value("type_overall").toInt();
        this->orders[numOfOrders].number=query.value("id").toInt();
        numOfOrders ++;
    }
    disPlay();


}

void message_view::disPlay()
{
    ui->total->display(numOfOrders);
    ui->No_->display(displayPointer + 1);
    ui->ddl->setText(orders[displayPointer].ddl);
    ui->from->setText(orders[displayPointer].address_from);
    ui->reward->display(orders[displayPointer].reward);
    ui->to->setText(orders[displayPointer].address_to);
    QString stringType;
    if(orders[displayPointer].type_overall == 1)stringType = "帮我取";
    else if(orders[displayPointer].type_overall == 2)stringType = "帮我买";
    else if(orders[displayPointer].type_overall == 3)stringType = "帮我送";
    else if(orders[displayPointer].type_overall == 4)stringType = "帮我做";
    else if(orders[displayPointer].type_overall == 5)stringType = "帮我寄";
    ui->type->setText(stringType);
}

message_view::~message_view()
{
    if(orders)delete []orders;
    delete ui;
}

void message_view::on_pushButton_3_clicked()
{
    rider* r = new rider(id);
    close();
    r->show();
}


void message_view::on_pushButton_2_clicked()
{
    if(this->displayPointer + 1 < this->numOfOrders)
    {
        this->displayPointer ++;
        this->disPlay();
    }
}


void message_view::on_pushButton_clicked()
{
    if(this->displayPointer - 1 >= 0)
    {
        this->displayPointer --;
        this->disPlay();
    }
}


void message_view::on_pushButton_4_clicked()
{
    // Database::cancelOrderByRider(orders[displayPointer].number,id);
    qDebug()<<orders[displayPointer].number<<id;
    if(Database::cancelOrderByRider(orders[displayPointer].number,id)){
        qDebug()<<"success";
    }
    Cancel_success* c=new Cancel_success;
    c->show();
    this->orders = new OrderMessage[50];
    this->displayPointer = 0;
    QSqlQuery query = Database::getOrdersByRidername(id);
    this->numOfOrders = 0;
    while (query.next()) {
        this->orders[numOfOrders].ddl = query.value("ddl").toString();
        this->orders[numOfOrders].address_from = query.value("address_from").toString();
        this->orders[numOfOrders].address_to = query.value("address_to").toString();
        this->orders[numOfOrders].reward = query.value("reward").toDouble();
        this->orders[numOfOrders].type_overall = query.value("type_overall").toInt();
        this->orders[numOfOrders].number=query.value("id").toInt();
        numOfOrders ++;
    }
    if(numOfOrders>0)
    disPlay();
    else{
        ui->from->setText("N/A");
        ui->to->setText("N/A");
        ui->ddl->setText("N/A");
        ui->type->setText("N/A");
        ui->No_->display(0);
        ui->reward->display(0);
        ui->No_->display(0);
        ui->total->display(0);
    }
}

