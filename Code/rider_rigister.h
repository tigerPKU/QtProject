#ifndef RIDER_RIGISTER_H
#define RIDER_RIGISTER_H

#include <QDialog>

namespace Ui {
class rider_rigister;
}

class rider_rigister : public QDialog
{
    Q_OBJECT

public:
    explicit rider_rigister(QWidget *parent = nullptr);
    ~rider_rigister();

private slots:
    void on_lcdNumber_overflow();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::rider_rigister *ui;
};

#endif // RIDER_RIGISTER_H
