#ifndef LOCATION_CHOOSE_H
#define LOCATION_CHOOSE_H

#include <QWidget>

namespace Ui {
class Location_choose;
}

struct QPointCompare {
    bool operator()(const QPoint &p1, const QPoint &p2) const {
        if (p1.x() < p2.x()) return true;
        if (p1.x() > p2.x()) return false;
        return p1.y() < p2.y();
    }
};

class Location_choose : public QWidget
{
    Q_OBJECT

public:
    int type,detail;
    explicit Location_choose(QWidget *parent = nullptr);
    Location_choose(int typee,int detaill);
    Location_choose();
    ~Location_choose();
    void mousePressEvent(QMouseEvent *event) override;
    QString findNearestString(const QPoint &point) const; // 查找最近的QString
    double manhattanDistance(const QPoint &p1, const QPoint &p2)const;
    const QPoint Addresses[15]={QPoint(69,403),QPoint(214,442),QPoint(299,373),QPoint(193,364),QPoint(251,351),QPoint(249,305)
                ,QPoint(246,273),QPoint(305,257),QPoint(310,325),QPoint(40,229)
                ,QPoint(39,175),QPoint(209,260),QPoint(138,336),QPoint(123,275),QPoint(227,149)};
    const QString Names[15]={"西南门","南门","邱德拔","新太阳","三教","二教"
                         ,"理教","东门","东南门","西侧门","西门","文史楼/老地学楼","燕南园","静园","一体"};
    QPoint Chosen_point;
    QString Chosen_name;
signals:
    void mouseClicked(QPoint pos);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Location_choose *ui;
};

#endif // LOCATION_CHOOSE_H
