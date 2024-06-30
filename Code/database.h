#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QSqlQuery>

class Database {
public:
    // 用户注册功能
    static bool registerUser(const QString& username, const QString& password);

    // 骑手注册功能
    static bool registerRider(const QString& username, const QString& password);

    // 用户登录验证
    static bool loginUser(const QString& username, const QString& password);

    // 骑手登录验证
    static bool loginRider(const QString& username, const QString& password);

    // 创建订单
    static bool createOrder(const QString& userName, const QString& ddl, const QString& addressFrom,const QString& addressTo, double xFrom, double yFrom, double reward, const QString& requirements, int typeOverall, int typeDetail);

    // 获取所有订单
    static QSqlQuery getOrders();

    // 骑手接单功能
    static bool acceptOrder(int orderId, const QString& riderName);

    // 更新骑手位置信息
    static bool updateRiderLocation(const QString& riderName, double x, double y);

    // 骑手取消订单功能
    static bool cancelOrderByRider(int orderId, const QString& riderName);

    // 用户取消订单功能
    static bool cancelOrderByUser(int orderId, const QString& userName);

    // 向订单添加消息功能
    static bool addMessageToOrder(int orderId, const QString& sender, const QString& message);

    // 获取订单消息功能
    static QString getOrderMessages(int orderId);

    // 获取骑手数量
    static int getRiderCount();

    // 根据用户名获取用户订单
    static QSqlQuery getOrdersByUsername(const QString& username);

    // 根据骑手用户名获取订单
    static QSqlQuery getOrdersByRidername(const QString& ridername);

    // 获取所有待处理订单
    static QSqlQuery getPendingOrders();

    // 获取距离最近的待处理订单
    static QSqlQuery getNearestPendingOrders(double riderX, double riderY);
};

// 创建数据库功能
void createDatabase();

#endif // DATABASE_H
