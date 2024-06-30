#ifndef MESSAGE_VIEW2_H
#define MESSAGE_VIEW2_H

#include "ordermessage.h"
#include <QDialog>

namespace Ui {
class message_view2;
}

class message_view2 : public QDialog
{
    Q_OBJECT
    QString id;
    OrderMessage* orders;
    int numOfOrders;
    int displayPointer;

public:
    explicit message_view2(QString id1, QString loc,QWidget *parent = nullptr);
    ~message_view2();
    void disPlay();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::message_view2 *ui;
};

#endif // MESSAGE_VIEW2_H
