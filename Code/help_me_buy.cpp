#include "help_me_buy.h"
#include "ui_help_me_buy.h"
#include "yonghu.h"
#include "ordermessage.h"
#include "mainwindow.h"
#include "dialogue_end.h"
#include "database.h"
#include "current_user.h"
#include "location_choose.h"
int detail1=0;
OrderMessage Help_me_buy::m=OrderMessage();
Help_me_buy::Help_me_buy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Help_me_buy)
{
    ui->setupUi(this);
    ui->textEdit->close();
    setWindowTitle("帮我买");

}

Help_me_buy::~Help_me_buy()
{
    delete ui;
}

void Help_me_buy::on_pushButton_clicked()
{
    close();
    yonghu* ui=new yonghu;
    ui->show();
}



void Help_me_buy::on_pushButton_2_clicked()
{

    QString s=ui->lineEdit->text();
    m.ddl=ui->timeEdit->text();
    m.reward=s.toDouble();
    // m.address_from=ui->textEdit_2->toPlainText();
    // m.address_to=ui->textEdit_3->toPlainText();
    m.requirements=ui->textEdit->toPlainText();
    m.type_overall=2;
    m.type_detail=1;
    // read();
    if(Database::createOrder(Current_username,m.ddl,m.address_from,m.address_to,m.x_start,m.y_start
                              ,m.reward,m.requirements,m.type_overall,detail1)){

        qDebug()<<"Order created";
    }
    Dialogue_end * ui2=new Dialogue_end;
    qDebug()<<m.address_from<<" "<<m.address_to<<" "<<m.x_start<<m.y_start;
    ui2->show();
    close();
}


void Help_me_buy::on_radioButton_clicked()
{
    detail1=1;

}


void Help_me_buy::on_radioButton_2_clicked()
{
    detail1=2;
}


void Help_me_buy::on_radioButton_3_clicked()
{
    detail1=3;
}

void Help_me_buy::on_radioButton_4_clicked()
{
    detail1=4;
}


void Help_me_buy::on_radioButton_5_clicked()
{
    detail1=5;
}


void Help_me_buy::on_radioButton_6_clicked()
{
    detail1=6;
}


void Help_me_buy::on_pushButton_3_clicked()
{
    Location_choose* loc=new Location_choose(1,1);
    loc->show();
}


void Help_me_buy::on_pushButton_4_clicked()
{
    // ui->label_5->setText(m.address_from);
    Location_choose* loc=new Location_choose(1,2);
    loc->show();
}


void Help_me_buy::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    // ui->label_6->setText(m.address_to);
}

