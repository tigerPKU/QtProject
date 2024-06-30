#ifndef MESSAGE_VIEW_H
#define MESSAGE_VIEW_H

#include "ordermessage.h"
#include <QDialog>

namespace Ui {
class message_view;
}

class message_view : public QDialog
{
    Q_OBJECT
    QString id;
    OrderMessage* orders;
    int numOfOrders;
    int displayPointer;

public:
    explicit message_view(QString id1, QWidget *parent = nullptr);
    ~message_view();
    void disPlay();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::message_view *ui;
};

#endif // MESSAGE_VIEW_H
