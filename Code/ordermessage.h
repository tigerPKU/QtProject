#ifndef ORDERMESSAGE_H
#define ORDERMESSAGE_H
#include <QApplication>
// #include<string>
class OrderMessage
{
public:
    OrderMessage();
    int number;
    QString ddl;
    QString address_from;
    QString address_to;
    double reward;
    QString requirements;
    int type_overall;//帮我取，帮我买，帮我送，帮我做，帮我寄
    int type_detail;//代取外卖，代取快递，自定义
    double x_start;
    double y_start;
    double x_end;
    double y_end;
    QString message_text[30];
};

#endif // ORDERMESSAGE_H
