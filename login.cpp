#include "login.h"

Login::Login(QObject *parent) : QObject(parent)
{

}

QWidget *Login::setLoginUi()
{
    QFormLayout *formLayout = new QFormLayout;

    this->name = new QLineEdit();
    this->name->setMinimumSize(200, 30);
    this->name->setPlaceholderText("optional");

    this->host = new QLineEdit();
    this->host->setMinimumSize(200, 30);
    this->host->setText("127.0.0.1");

    this->port = new QLineEdit();
    this->port->setMinimumSize(200, 30);
    this->port->setPlaceholderText("3306");
    this->port->setText("3306");

    this->username = new QLineEdit();
    this->username->setMinimumSize(200, 30);

    this->password = new QLineEdit();
    this->password->setMinimumSize(200, 30);
    this->password->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    this->database = new QLineEdit();
    this->database->setMinimumSize(200, 30);
    this->database->setPlaceholderText("optional");

    this->buttonConnect = new QPushButton("connect");
    this->buttonConnect->setFixedWidth(120);

    formLayout->addRow("Name: ", this->name);
    formLayout->addRow("Host: ", this->host);
    formLayout->addRow("Port: ", this->port);
    formLayout->addRow("Username: ", this->username);
    formLayout->addRow("Password: ", this->password);
    formLayout->addRow("Database", this->database);
    formLayout->addRow("", this->buttonConnect);
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setContentsMargins(50, 100, 50, 50);

    QGroupBox *groupBox = new QGroupBox();
    groupBox->setLayout(formLayout);
    groupBox->setMinimumWidth(300);

    connect(this->buttonConnect, SIGNAL(clicked()), this, SLOT(acceptLogin()));
    connect(this, SIGNAL(reloadCentralWidget()), this->parent(), SLOT(reloadCentralWidget()));

    return groupBox;
}

void Login::acceptLogin()
{
    QString name = this->name->text();
    QString host = this->host->text();
    QString port = this->port->text();
    QString username = this->username->text();
    QString password = this->password->text();

    name = name.isEmpty() ? host : name;

    QJsonObject jsonObj;
    jsonObj.insert("name", name);
    jsonObj.insert("host", host);
    jsonObj.insert("port", port);
    jsonObj.insert("username", username);
    jsonObj.insert("password", password);

    Mysql& mysqlHandle = Mysql::getInstance();

    if (mysqlHandle.setConnect(jsonObj)) {
        this->fileHandle = new FileSystem();
        this->fileHandle->writeConfig(jsonObj);

        mysqlHandle.dbInstances.append(name);

        qDebug() << "singleton instance";
        emit reloadCentralWidget();
    } else {
        qDebug() << mysqlHandle.connectError();
    }
}

QWidget *Login::setListWidget()
{
    this->fileHandle = new FileSystem();
    QJsonObject config = this->fileHandle->readConfig();

    QJsonObject::Iterator it;

    QListWidget *listWidget = new QListWidget();

    for (it = config.begin(); it != config.end(); it++) {
        QJsonObject jsonObj = it.value().toObject();
        listWidget->addItem(new QListWidgetItem(QIcon(":/resource/images/database-small.ico"), jsonObj.value("name").toString()));
    }

    listWidget->setMaximumWidth(270);
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(singleClicked(QListWidgetItem*)));
    connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(doubleClicked(QListWidgetItem*)));

    return listWidget;
}

void Login::singleClicked(QListWidgetItem *item)
{    
    QString name = item->text();
    this->fileHandle = new FileSystem();
    QJsonObject config = this->fileHandle->readConfig();
    QJsonObject jsonObj = config.value(name).toObject();

    this->name->setText(jsonObj.value("name").toString());
    this->host->setText(jsonObj.value("host").toString());
    this->port->setText(jsonObj.value("port").toString());
    this->username->setText(jsonObj.value("username").toString());
    this->password->setText(jsonObj.value("password").toString());
}

void Login::doubleClicked(QListWidgetItem *item)
{
    qDebug() << item->text() << "2332";
}

Login::~Login()
{

}
