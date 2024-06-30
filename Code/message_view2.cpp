#include "message_view2.h"
#include "rider.h"
#include "ui_message_view2.h"
#include "database.h"
message_view2::message_view2(QString id1,QString loc, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::message_view2)
    , id(id1)
{
    ui->setupUi(this);
    ui->label_12->setText(id);
    ui->label_13->setText(loc);
    setWindowTitle("查看订单");
    this->orders = new OrderMessage[50];
    this->displayPointer = 0;
    QSqlQuery query = Database::getNearestPendingOrders(rider::Current_point.x(),rider::Current_point.y());
    this->numOfOrders = 0;
    while (query.next()) {
        this->orders[numOfOrders].ddl = query.value("ddl").toString();
        this->orders[numOfOrders].address_from = query.value("address_from").toString();
        this->orders[numOfOrders].address_to = query.value("address_to").toString();
        this->orders[numOfOrders].reward = query.value("reward").toDouble();
        this->orders[numOfOrders].type_overall = query.value("type_overall").toInt();
        this->orders[numOfOrders].number = query.value("id").toInt();
        numOfOrders ++;
    }
    disPlay();


}

void message_view2::disPlay()
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


message_view2::~message_view2()
{
    if(this->orders)delete[] orders;
    delete ui;
}

void message_view2::on_pushButton_3_clicked()
{
    rider* r = new rider(id,rider::Current_loc);
    close();
    r->show();
}


void message_view2::on_pushButton_2_clicked()
{
    if(this->displayPointer + 1 < this->numOfOrders)
    {
        this->displayPointer ++;
        this->disPlay();
    }
}


void message_view2::on_pushButton_clicked()
{
    if(this->displayPointer - 1 >= 0)
    {
        this->displayPointer --;
        this->disPlay();
    }
}


void message_view2::on_pushButton_4_clicked()
{
    Database::acceptOrder(this->orders[displayPointer].number, this->id);
    rider* r = new rider(id);
    close();
    r->show();

}

