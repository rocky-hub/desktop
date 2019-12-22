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
    bool setConnect(QJsonObject jsonObj);
    void setDatabase(QString database);
    QVector<QString> database();
    QVector<QString> table(QString database);
    QVector<QString> column(QString table);
    void value();
    QString connectError();
    QSqlError addConnection(const QString name, const QString host, const QString user,
                            const QString passwd, int port, const QString dbName = nullptr);
    QSqlDatabase currentConnection() const;

    void setCurrenctDatabase();

    QSqlDatabase dbHandle;
    QVector<QString> dbInstances;
    QString currentInstance;
    QString currenctTable;
    QString currentTool;
    QString currentConnectionName;
    QString currentDatabaseName;

signals:

public slots:
};

#endif // MYSQL_H
