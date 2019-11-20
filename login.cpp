#include "login.h"

login::login(QObject *parent) : QObject(parent)
{

}

QWidget *login::setLoginUi()
{
    QFormLayout *formLayout = new QFormLayout;

    this->name = new QLineEdit();
    this->name->setMinimumSize(200, 30);

    this->host = new QLineEdit();
    this->host->setMinimumSize(200, 30);

    this->port = new QLineEdit();
    this->port->setMinimumSize(200, 30);
    this->port->setPlaceholderText("3306");

    this->username = new QLineEdit();
    this->username->setMinimumSize(200, 30);

    this->password = new QLineEdit();
    this->password->setMinimumSize(200, 30);
    this->password->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    this->buttonConnect = new QPushButton("connect");
    this->buttonConnect->setFixedWidth(120);

    formLayout->addRow("Name: ", this->name);
    formLayout->addRow("Host: ", this->host);
    formLayout->addRow("Port: ", this->port);
    formLayout->addRow("Username: ", this->username);
    formLayout->addRow("Password: ", this->password);
    formLayout->addRow("", this->buttonConnect);
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setContentsMargins(50, 100, 50, 50);

    QGroupBox *groupBox = new QGroupBox();
    groupBox->setLayout(formLayout);
    groupBox->setMinimumWidth(300);

    connect(this->buttonConnect, SIGNAL(clicked()), this, SLOT(acceptLogin()));

    return groupBox;
}

void login::acceptLogin()
{
    QString name = this->name->text();
    QString host = this->host->text();
    QString port = this->port->text();
    QString username = this->username->text();
    QString password = this->password->text();

    QJsonObject jsonObj;
    jsonObj.insert("name", name);
    jsonObj.insert("host", host);
    jsonObj.insert("port", port);
    jsonObj.insert("username", username);
    jsonObj.insert("password", password);

    jsonObj.insert(name, jsonObj);

    this->fileHandle = new fileSystem();
    this->fileHandle->writeConfig(jsonObj);
}

login::~login()
{

}
