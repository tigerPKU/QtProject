#include "mainwindow.h"
#include "database.h"
#include <QApplication>
QString user_name;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createDatabase();
    MainWindow w;
    w.show();
    return a.exec();
}
