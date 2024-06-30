#include "dialogue_end.h"
#include "ui_dialogue_end.h"
#include "mainwindow.h"
#include "yonghu.h"
Dialogue_end::Dialogue_end(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dialogue_end)
{
    ui->setupUi(this);
    setWindowTitle("提示");
}

Dialogue_end::~Dialogue_end()
{
    delete ui;
}

void Dialogue_end::on_pushButton_clicked()
{
    close();
    yonghu* ui1=new yonghu;
    ui1->show();
}

