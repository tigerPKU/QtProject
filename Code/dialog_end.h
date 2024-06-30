#ifndef DIALOG_END_H
#define DIALOG_END_H

#include <QWidget>

namespace Ui {
class Dialog_end;
}

class Dialog_end : public QWidget
{
    Q_OBJECT

public:
    explicit Dialog_end(QWidget *parent = nullptr);
    ~Dialog_end();

private:
    Ui::Dialog_end *ui;
};

#endif // DIALOG_END_H
