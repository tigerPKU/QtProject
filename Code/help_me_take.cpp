#include "help_me_take.h"
#include "ui_help_me_take.h"
#include "yonghu.h"
#include "ordermessage.h"
#include "mainwindow.h"
#include "dialogue_end.h"
#include "database.h"
#include "current_user.h"
#include "location_choose.h"
int detail;
OrderMessage help_me_take::m=OrderMessage();
help_me_take::help_me_take(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::help_me_take)
{
    ui->setupUi(this);
    ui->plainTextEdit->close();
    setWindowTitle("帮我取");
}

help_me_take::~help_me_take()
{
    delete ui;
}

void help_me_take::on_radioButton_clicked()
{
    ui->plainTextEdit->close();
    detail=1;
}


void help_me_take::on_radioButton_2_clicked()
{
    ui->plainTextEdit->close();
    detail=2;
}


void help_me_take::on_radioButton_3_clicked()
{
    detail=3;
}


void help_me_take::on_pushButton_2_clicked()
{
    close();
    yonghu* ui=new yonghu;
    ui->show();
}


void help_me_take::on_pushButton_clicked()
{
    QString s=ui->lineEdit->text();
    m.ddl=ui->timeEdit->text();
    m.reward=s.toDouble();
    // m.address_from=ui->textEdit_2->toPlainText();
    // m.address_to=ui->textEdit_3->toPlainText();
    m.requirements=ui->textEdit->toPlainText();
    m.type_overall=1;
    m.type_detail=1;
    // read();
    qDebug()<<Current_username<<m.ddl<<m.address_from<<m.x_start<<m.y_start<<m.reward<<m.requirements<<m.type_overall<<detail;
    Database::createOrder(Current_username,m.ddl,m.address_from,m.address_to,m.x_start,m.y_start,m.reward,m.requirements,m.type_overall,detail);
    Dialogue_end * ui2=new Dialogue_end;
    ui2->show();
    close();
    // MainWindow* ui1=new MainWindow;
}


void help_me_take::on_pushButton_3_clicked()
{
    Location_choose* loc=new Location_choose(2,1);
    loc->show();
}


void help_me_take::on_pushButton_4_clicked()
{
    // ui->label_6->setText(m.address_from);
    Location_choose* loc=new Location_choose(2,2);
    loc->show();
}


void help_me_take::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    // ui->label_7->setText(m.address_to);
}

