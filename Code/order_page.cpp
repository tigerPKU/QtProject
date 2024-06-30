#include "order_page.h"
#include "ui_order_page.h"
#include "yonghu.h"
#include "database.h"
#include "current_user.h"
#include "ordermessage.h"
#include "cancel_success.h"
// #include<iostream>
Order_Page::Order_Page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Order_Page)
{
    ui->setupUi(this);
    setWindowTitle("订单页");
    if(1){//有数据
        // Database::getOrdersByUsername("user");
        QSqlQuery query = Database::getOrdersByUsername(Current_username);
        // qDebug()<<Current_username;
        // QString s;
        // QSqlQuery query = getOrdersByUsername(username);
        Od=new OrderMessage[100];
        Status=new QString[100];
        cnt=0;
        while (query.next()) {
            int id = query.value("id").toInt();
            QString userName = query.value("user_name").toString();
            QString riderName = query.value("rider_name").toString(); // 添加了 riderName 变量
            QString ddl = query.value("ddl").toString();
            QString addressFrom = query.value("address_from").toString();
            QString addressTo = query.value("address_to").toString();
            double reward = query.value("reward").toDouble();
            int typeOverall = query.value("type_overall").toInt();
            int typeDetail = query.value("type_detail").toInt();
            QString status = query.value("status").toString();
            Od[cnt].type_detail=typeDetail;
            Od[cnt].type_overall=typeOverall;
            Od[cnt].address_from=addressFrom;
            Od[cnt].address_to=addressTo;
            Od[cnt].ddl=ddl;
            Od[cnt].number=id;
            Status[cnt]=status;
            //
            qDebug()<<id<<userName<<riderName<<status;
            cnt++;
        }
        if(cnt==0){
            ui->label_overalltype->setText("N/A");
            ui->label_detailtype->setText("N/A");
            ui->label_Situa->setText("N/A");
            ui->label_From->setText("N/A");
            ui->label_To->setText("N/A");
            ui->label_ddl->setText("N/A");
            return;
        }
        //Ordermessage s=write();
        ui->label_Situa->setText(Status[current_page]);
        ui->label_ddl->setText(Od[current_page].ddl);
        ui->label_From->setText(Od[current_page].address_from);
        ui->label_To->setText(Od[current_page].address_to);
        if(Od[current_page].type_overall==1){
            ui->label_overalltype->setText("帮我取");
            if(Od[current_page].type_detail==1){
                ui->label_detailtype->setText("代取外卖");
            }
            else if(Od[current_page].type_detail==2){
                ui->label_detailtype->setText("代取快递");
            }
            else if(Od[current_page].type_detail==3){
                ui->label_detailtype->setText("自定义");
            }
        }
        else if(Od[current_page].type_overall==2){//买药，买水，买奶茶，买水果，买饭，自定义
            ui->label_overalltype->setText("帮我买");
            if(Od[current_page].type_detail==1){
                ui->label_detailtype->setText("买药");
            }
            else if(Od[current_page].type_detail==2){
                ui->label_detailtype->setText("买水");
            }
            else if(Od[current_page].type_detail==3){
                ui->label_detailtype->setText("买奶茶");
            }
            else if(Od[current_page].type_detail==4){
                ui->label_detailtype->setText("买水果");
            }
            else if(Od[current_page].type_detail==5){
                ui->label_detailtype->setText("买饭");
            }
            else if(Od[current_page].type_detail==6){
                ui->label_detailtype->setText("自定义");
            }
        }
        if(cnt!=0)
            current_page=(current_page+1)%cnt;
    }
}

Order_Page::~Order_Page()
{
    delete ui;
}

void Order_Page::on_pushButton_clicked()
{
    close();
    yonghu *ui1=new yonghu;
    ui1->show();
}


void Order_Page::on_pushButton_2_clicked()
{
    if(cnt==0){
        ui->label_overalltype->setText("N/A");
        ui->label_detailtype->setText("N/A");
        ui->label_Situa->setText("N/A");
        ui->label_From->setText("N/A");
        ui->label_To->setText("N/A");
        ui->label_ddl->setText("N/A");
        return;
    }
    ui->label_Situa->setText(Status[current_page]);
    ui->label_ddl->setText(Od[current_page].ddl);
    ui->label_From->setText(Od[current_page].address_from);
    ui->label_To->setText(Od[current_page].address_to);
    if(Od[current_page].type_overall==1){
        ui->label_overalltype->setText("帮我取");
        if(Od[current_page].type_detail==1){
            ui->label_detailtype->setText("代取外卖");
        }
        else if(Od[current_page].type_detail==2){
            ui->label_detailtype->setText("代取快递");
        }
        else if(Od[current_page].type_detail==3){
            ui->label_detailtype->setText("自定义");
        }
    }
    else if(Od[current_page].type_overall==2){
        ui->label_overalltype->setText("帮我买");
        if(Od[current_page].type_detail==1){
            ui->label_detailtype->setText("买药");
        }
        else if(Od[current_page].type_detail==2){
            ui->label_detailtype->setText("买水");
        }
        else if(Od[current_page].type_detail==3){
            ui->label_detailtype->setText("买奶茶");
        }
        else if(Od[current_page].type_detail==4){
            ui->label_detailtype->setText("买水果");
        }
        else if(Od[current_page].type_detail==5){
            ui->label_detailtype->setText("买饭");
        }
        else if(Od[current_page].type_detail==6){
            ui->label_detailtype->setText("自定义");
        }
    }
    if(cnt!=0)
    current_page=(current_page+1)%cnt;
}


void Order_Page::on_pushButton_3_clicked()
{
    Database::cancelOrderByUser(Od[current_page].number,Current_username);
    Cancel_success *c=new Cancel_success;
    c->show();
    QSqlQuery query = Database::getOrdersByUsername(Current_username);
    // qDebug()<<Current_username;
    // QString s;
    // QSqlQuery query = getOrdersByUsername(username);
    Od=new OrderMessage[100];
    Status=new QString[100];
    cnt=0;
    while (query.next()) {
        int id = query.value("id").toInt();
        QString userName = query.value("user_name").toString();
        QString riderName = query.value("rider_name").toString(); // 添加了 riderName 变量
        QString ddl = query.value("ddl").toString();
        QString addressFrom = query.value("address_from").toString();
        QString addressTo = query.value("address_to").toString();
        double reward = query.value("reward").toDouble();
        int typeOverall = query.value("type_overall").toInt();
        int typeDetail = query.value("type_detail").toInt();
        QString status = query.value("status").toString();
        Od[cnt].type_detail=typeDetail;
        Od[cnt].type_overall=typeOverall;
        Od[cnt].address_from=addressFrom;
        Od[cnt].address_to=addressTo;
        Od[cnt].ddl=ddl;
        Od[cnt].number=id;
        Status[cnt]=status;
        //
        qDebug()<<id<<userName<<riderName<<status;
        cnt++;
    }
    if(cnt==0){
        ui->label_overalltype->setText("N/A");
        ui->label_detailtype->setText("N/A");
        ui->label_Situa->setText("N/A");
        ui->label_From->setText("N/A");
        ui->label_To->setText("N/A");
        ui->label_ddl->setText("N/A");
    }
    else{
        ui->label_Situa->setText(Status[current_page]);
        ui->label_ddl->setText(Od[current_page].ddl);
        ui->label_From->setText(Od[current_page].address_from);
        ui->label_To->setText(Od[current_page].address_to);
        if(Od[current_page].type_overall==1){
            ui->label_overalltype->setText("帮我取");
            if(Od[current_page].type_detail==1){
                ui->label_detailtype->setText("代取外卖");
            }
            else if(Od[current_page].type_detail==2){
                ui->label_detailtype->setText("代取快递");
            }
            else if(Od[current_page].type_detail==3){
                ui->label_detailtype->setText("自定义");
            }
        }
        else if(Od[current_page].type_overall==2){//买药，买水，买奶茶，买水果，买饭，自定义
            ui->label_overalltype->setText("帮我买");
            if(Od[current_page].type_detail==1){
                ui->label_detailtype->setText("买药");
            }
            else if(Od[current_page].type_detail==2){
                ui->label_detailtype->setText("买水");
            }
            else if(Od[current_page].type_detail==3){
                ui->label_detailtype->setText("买奶茶");
            }
            else if(Od[current_page].type_detail==4){
                ui->label_detailtype->setText("买水果");
            }
            else if(Od[current_page].type_detail==5){
                ui->label_detailtype->setText("买饭");
            }
            else if(Od[current_page].type_detail==6){
                ui->label_detailtype->setText("自定义");
            }
        }
        if(cnt!=0)
            current_page=(current_page+1)%cnt;
    }
}

