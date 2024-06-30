#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include <QWidget>

namespace Ui {
class User_login;
}

class User_login : public QWidget
{
    Q_OBJECT

public:
    explicit User_login(QWidget *parent = nullptr);
    ~User_login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::User_login *ui;
};

#endif // USER_LOGIN_H
