#ifndef HELP_ME_SEND_H
#define HELP_ME_SEND_H

#include <QWidget>

namespace Ui {
class Help_me_send;
}

class Help_me_send : public QWidget
{
    Q_OBJECT

public:
    explicit Help_me_send(QWidget *parent = nullptr);
    ~Help_me_send();
    static int detail;

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::Help_me_send *ui;
};
// int Help_me_send::detail=1;
#endif // HELP_ME_SEND_H
