#ifndef HELP_ME_BUY_H
#define HELP_ME_BUY_H
#include "ordermessage.h"
#include <QWidget>

namespace Ui {
class Help_me_buy;
}

class Help_me_buy : public QWidget
{
    Q_OBJECT

public:
    explicit Help_me_buy(QWidget *parent = nullptr);
    ~Help_me_buy();
    static OrderMessage m;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Help_me_buy *ui;
};

#endif // HELP_ME_BUY_H
