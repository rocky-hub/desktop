#include "login.h"

login::login(QObject *parent) : QObject(parent)
{

}

QWidget *login::setLoginUi()
{
    QGroupBox *groupBox = new QGroupBox();

    QFormLayout *formLayout = new QFormLayout;

    QLineEdit *connectNameInput = new QLineEdit();
    connectNameInput->setMinimumSize(200, 30);
    QLineEdit *hostInput = new QLineEdit();
    hostInput->setMinimumSize(200, 30);
    QLineEdit *portInput = new QLineEdit();
    portInput->setMinimumSize(200, 30);
    QLineEdit *usernameInput = new QLineEdit();
    usernameInput->setMinimumSize(200, 30);
    QLineEdit *password = new QLineEdit();
    password->setMinimumSize(200, 30);
    QPushButton *button = new QPushButton("connect");
    button->setFixedWidth(120);

    formLayout->addRow("Name: ", connectNameInput);
    formLayout->addRow("Host: ", hostInput);
    formLayout->addRow("Port: ", portInput);
    formLayout->addRow("Username: ", usernameInput);
    formLayout->addRow("Password: ", password);
    formLayout->addRow("", button);
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setContentsMargins(50, 100, 50, 50);

    groupBox->setLayout(formLayout);
    groupBox->setMinimumWidth(300);

    connect(button, SIGNAL(clicked()), this, SLOT(acceptLogin()));

    return groupBox;
}

void login::acceptLogin()
{
    qDebug() << "singal";
}

login::~login()
{

}
