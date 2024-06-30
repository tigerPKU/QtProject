#include "database.h"
#include <QtSql>
#include <QMessageBox>
#include <QtMath> // 用于计算距离

bool Database::registerUser(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool Database::registerRider(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("INSERT INTO riders (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool Database::loginUser(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec() || !query.next()) {
        return false;
    }

    return true;
}

bool Database::loginRider(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM riders WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec() || !query.next()) {
        return false;
    }

    return true;
}

bool Database::createOrder(const QString& userName, const QString& ddl, const QString& addressFrom, const QString& addressTo, double xFrom, double yFrom, double reward, const QString& requirements, int typeOverall, int typeDetail) {
    QSqlQuery query;
    query.prepare("INSERT INTO orders (user_name, requirements, status, ddl, address_from, address_to, reward, type_overall, type_detail, x_from, y_from, messages) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(userName);
    query.addBindValue(requirements);
    query.addBindValue("pending");
    query.addBindValue(ddl);
    query.addBindValue(addressFrom);
    query.addBindValue(addressTo);
    query.addBindValue(reward);
    query.addBindValue(typeOverall);
    query.addBindValue(typeDetail);
    query.addBindValue(xFrom);
    query.addBindValue(yFrom);
    query.addBindValue(""); // 初始化消息为空字符串

    if (!query.exec()) {
        qDebug() << "Error executing SQL:" << query.lastError().text();
        return false;
    }

    return true;
}


QSqlQuery Database::getOrders() {
    QSqlQuery query;
    query.prepare("SELECT * FROM orders");
    query.exec();
    return query;
}

bool Database::acceptOrder(int orderId, const QString& riderName) {
    QSqlQuery query;
    query.prepare("UPDATE orders SET status = 'accepted', rider_name = ? WHERE id = ?");
    query.addBindValue(riderName);
    query.addBindValue(orderId);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool Database::updateRiderLocation(const QString& riderName, double x, double y) {
    QSqlQuery query;
    query.prepare("UPDATE riders SET x = ?, y = ? WHERE username = ?");
    query.addBindValue(x);
    query.addBindValue(y);
    query.addBindValue(riderName);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool Database::cancelOrderByRider(int orderId, const QString& riderName) {
    QSqlQuery query;
    query.prepare("UPDATE orders SET status = 'pending', rider_name = NULL WHERE id = ? AND rider_name = ?");
    query.addBindValue(orderId);
    query.addBindValue(riderName);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool Database::cancelOrderByUser(int orderId, const QString& userName) {
    QSqlQuery query;
    query.prepare("DELETE FROM orders WHERE id = ? AND user_name = ?");
    query.addBindValue(orderId);
    query.addBindValue(userName);

    if (!query.exec()) {
        return false;
    }

    return true;
}

bool Database::addMessageToOrder(int orderId, const QString& sender, const QString& message) {
    QSqlQuery query;
    query.prepare("SELECT messages FROM orders WHERE id = ?");
    query.addBindValue(orderId);

    if (!query.exec() || !query.next()) {
        return false;
    }

    QString currentMessages = query.value(0).toString();
    QString newMessage = sender + ": " + message;
    currentMessages += "\n" + newMessage;

    query.prepare("UPDATE orders SET messages = ? WHERE id = ?");
    query.addBindValue(currentMessages);
    query.addBindValue(orderId);

    if (!query.exec()) {
        return false;
    }

    return true;
}

QString Database::getOrderMessages(int orderId) {
    QSqlQuery query;
    query.prepare("SELECT messages FROM orders WHERE id = ?");
    query.addBindValue(orderId);

    if (!query.exec() || !query.next()) {
        return QString();
    }

    return query.value(0).toString();
}

int Database::getRiderCount() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM riders");

    if (!query.exec() || !query.next()) {
        return -1;
    }

    return query.value(0).toInt();
}

QSqlQuery Database::getOrdersByUsername(const QString& username) {
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE user_name = ?");
    query.addBindValue(username);
    query.exec();
    return query;
}

QSqlQuery Database::getOrdersByRidername(const QString& ridername) {
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE rider_name = ?");
    query.addBindValue(ridername);
    query.exec();
    return query;
}

QSqlQuery Database::getPendingOrders() {
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE status = 'pending'");
    query.exec();
    return query;
}

QSqlQuery Database::getNearestPendingOrders(double riderX, double riderY) {
    QSqlQuery query;
    query.prepare("SELECT *, ((x_from - ?)*(x_from - ?) + (y_from - ?)*(y_from - ?)) AS distance FROM orders WHERE status = 'pending' ORDER BY distance ASC");
    query.addBindValue(riderX);
    query.addBindValue(riderX);
    query.addBindValue(riderY);
    query.addBindValue(riderY);
    query.exec();
    return query;
}

void createDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("delivery_platform.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to open database.");
        return;
    }

    QSqlQuery query;
    // 用户表
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY,"
               "username TEXT UNIQUE,"
               "password TEXT"
               ")");
    // 骑手表
    query.exec("CREATE TABLE IF NOT EXISTS riders ("
               "id INTEGER PRIMARY KEY,"
               "username TEXT UNIQUE,"
               "password TEXT,"
               "x REAL,"
               "y REAL"
               ")");
    // 订单表
    query.exec("CREATE TABLE IF NOT EXISTS orders ("
               "id INTEGER PRIMARY KEY,"
               "user_name TEXT,"
               "rider_name TEXT,"
               "requirements TEXT,"
               "status TEXT,"
               "ddl TEXT,"
               "address_from TEXT,"
               "address_to TEXT,"
               "reward REAL,"
               "type_overall INTEGER,"
               "type_detail INTEGER,"
               "x_from REAL,"
               "y_from REAL,"
               "messages TEXT"
               ")");

    //db.close();
}

