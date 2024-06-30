#ifndef RIDER_RIGISTER_SUCCESS_H
#define RIDER_RIGISTER_SUCCESS_H

#include <QDialog>

namespace Ui {
class rider_rigister_success;
}

class rider_rigister_success : public QDialog
{
    Q_OBJECT

public:
    explicit rider_rigister_success(QWidget *parent = nullptr);
    ~rider_rigister_success();

private slots:
    void on_lcdNumber_overflow();

    void on_pushButton_clicked();

private:
    Ui::rider_rigister_success *ui;
};

#endif // RIDER_RIGISTER_SUCCESS_H
