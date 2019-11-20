#ifndef LOGIN_H
#define LOGIN_H

#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QMap>
#include <QJsonObject>
#include "fileSystem.h"

class login : public QObject
{
    Q_OBJECT

public:
    explicit login(QObject *parent = nullptr);
    ~login();
    QWidget *setLoginUi();
    QLineEdit *name;
    QLineEdit *host;
    QLineEdit *port;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *buttonConnect;
    fileSystem *fileHandle;

signals:

public slots:
    void acceptLogin();
};

#endif // LOGIN_H
