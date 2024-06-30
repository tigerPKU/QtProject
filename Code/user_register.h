#ifndef USER_REGISTER_H
#define USER_REGISTER_H

#include <QWidget>

namespace Ui {
class User_register;
}

class User_register : public QWidget
{
    Q_OBJECT

public:
    explicit User_register(QWidget *parent = nullptr);
    ~User_register();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::User_register *ui;
};

#endif // USER_REGISTER_H
