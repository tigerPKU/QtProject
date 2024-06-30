#include "cancel_success.h"
#include "ui_cancel_success.h"

Cancel_success::Cancel_success(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cancel_success)
{
    ui->setupUi(this);
    setWindowTitle("提示");
}

Cancel_success::~Cancel_success()
{
    delete ui;
}

void Cancel_success::on_pushButton_clicked()
{
    close();
}

