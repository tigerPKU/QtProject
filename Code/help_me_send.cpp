#include "help_me_send.h"
#include "ui_help_me_send.h"

Help_me_send::Help_me_send(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Help_me_send)
{
    ui->setupUi(this);
    ui->textEdit->close();
}

Help_me_send::~Help_me_send()
{
    delete ui;
}

void Help_me_send::on_radioButton_clicked()
{
    ui->textEdit->close();
    Help_me_send::detail=1;
}


void Help_me_send::on_radioButton_2_clicked()
{
    ui->textEdit->close();
    Help_me_send::detail=1;
}


void Help_me_send::on_radioButton_3_clicked()
{
    ui->textEdit->close();
    Help_me_send::detail=1;
}


void Help_me_send::on_radioButton_4_clicked()
{
    ui->textEdit->close();
}

