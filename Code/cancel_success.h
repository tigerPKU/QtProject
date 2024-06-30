#ifndef CANCEL_SUCCESS_H
#define CANCEL_SUCCESS_H

#include <QWidget>

namespace Ui {
class Cancel_success;
}

class Cancel_success : public QWidget
{
    Q_OBJECT

public:
    explicit Cancel_success(QWidget *parent = nullptr);
    ~Cancel_success();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Cancel_success *ui;
};

#endif // CANCEL_SUCCESS_H
