#ifndef HELP_ME_TAKE_H
#define HELP_ME_TAKE_H

#include <QWidget>
#include "ordermessage.h"
namespace Ui {
class help_me_take;
}

class help_me_take : public QWidget
{
    Q_OBJECT

public:
    explicit help_me_take(QWidget *parent = nullptr);
    ~help_me_take();
    static OrderMessage m;

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::help_me_take *ui;
};

#endif // HELP_ME_TAKE_H
