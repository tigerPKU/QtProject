#ifndef USER_REGISTER_SUCCESS_H
#define USER_REGISTER_SUCCESS_H

#include <QWidget>

namespace Ui {
class User_register_success;
}

class User_register_success : public QWidget
{
    Q_OBJECT

public:
    explicit User_register_success(QWidget *parent = nullptr);
    ~User_register_success();

private slots:
    void on_pushButton_clicked();

private:
    Ui::User_register_success *ui;
};

#endif // USER_REGISTER_SUCCESS_H
