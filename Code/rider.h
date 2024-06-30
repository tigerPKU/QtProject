#ifndef RIDER_H
#define RIDER_H

#include <QDialog>

namespace Ui {
class rider;
}

class rider : public QDialog
{
    Q_OBJECT

public:
    explicit rider(QWidget *parent = nullptr);
    explicit rider(QString id1, QString loc1="",QWidget *parent = nullptr);
    ~rider();
    QString id;
    static QString Current_loc;
    static QPoint Current_point;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::rider *ui;
};

#endif // RIDER_H
