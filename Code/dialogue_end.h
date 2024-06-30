#ifndef DIALOGUE_END_H
#define DIALOGUE_END_H

#include <QWidget>

namespace Ui {
class Dialogue_end;
}

class Dialogue_end : public QWidget
{
    Q_OBJECT

public:
    explicit Dialogue_end(QWidget *parent = nullptr);
    ~Dialogue_end();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogue_end *ui;
};

#endif // DIALOGUE_END_H
