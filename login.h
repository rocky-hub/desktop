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

class login : public QObject
{
    Q_OBJECT

public:
    explicit login(QObject *parent = nullptr);
    ~login();
    QWidget *setLoginUi();

signals:

public slots:
    void acceptLogin();
};

#endif // LOGIN_H
