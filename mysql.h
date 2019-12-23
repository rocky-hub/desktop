#ifndef MYSQL_H
#define MYSQL_H

#include <QWidget>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>
#include <QJsonObject>
#include <QVector>
#include <QDebug>

class Mysql : public QWidget
{
    Q_OBJECT
private:
    Mysql() {}
    Mysql(const Mysql&) = delete;
    Mysql& operator = (const Mysql&) = delete;
    static Mysql* instance;
public:
    static Mysql& getInstance();
    QVector<QString> database();
    QVector<QString> table();
    QVector<QString> column();
    QSqlError addConnection(const QString name, const QString host, const QString user,
                            const QString passwd, int port, const QString dbName = nullptr);
    QSqlDatabase currentConnection() const;
    void setCurrenctDatabase(const QString databaseName);

    QString currentConnectionName;
    QString currentDatabaseName;
    QString currenctTableName;

signals:

public slots:
};

#endif // MYSQL_H
