#include <QCoreApplication>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QTcpSocket socket;
    qDebug() << "Network object created. Socket state:" << socket.state();


    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");      // адрес сервера PostgreSQL
    db.setPort(5432);                 // стандартный порт PostgreSQL
    db.setDatabaseName("testdb");     // имя базы данных
    db.setUserName("postgres");       // пользователь
    db.setPassword("postgres");       // пароль

    if (db.open()) {
        qDebug() << "Connected to PostgreSQL successfully!";
        qDebug() << "Driver:" << db.driverName();
        db.close();
    } else {
        qDebug() << "Failed to connect to PostgreSQL:"
                 << db.lastError().text();
    }

    return 0;
}
