#include "dialog_end.h"
#include "ui_dialog_end.h"

Dialog_end::Dialog_end(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dialog_end)
{
    ui->setupUi(this);
}

Dialog_end::~Dialog_end()
{
    delete ui;
}
