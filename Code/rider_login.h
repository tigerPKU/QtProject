#ifndef RIDER_LOGIN_H
#define RIDER_LOGIN_H

#include <QDialog>

namespace Ui {
class rider_login;
}

class rider_login : public QDialog
{
    Q_OBJECT

public:
    explicit rider_login(QWidget *parent = nullptr);
    ~rider_login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::rider_login *ui;
};

#endif // RIDER_LOGIN_H
