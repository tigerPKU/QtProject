#ifndef YONGHU_H
#define YONGHU_H

#include <QWidget>

namespace Ui {
class yonghu;
}

class yonghu : public QWidget
{
    Q_OBJECT

public:
    explicit yonghu(QWidget *parent = nullptr);
    ~yonghu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::yonghu *ui;
};

#endif // YONGHU_H
