#ifndef ORDER_PAGE_H
#define ORDER_PAGE_H
#include "ordermessage.h"
#include <QWidget>

namespace Ui {
class Order_Page;
}

class Order_Page : public QWidget
{
    Q_OBJECT

public:
    explicit Order_Page(QWidget *parent = nullptr);
    ~Order_Page();
    OrderMessage* Od;
    QString *Status;
    int cnt;
    int current_page=0;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Order_Page *ui;
};

#endif // ORDER_PAGE_H
