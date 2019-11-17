#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi(QMainWindow *mainWindow)
{
    if (mainWindow->objectName().isEmpty()) {
        mainWindow->setObjectName("main window");
    }

    mainWindow->setWindowIcon(QIcon(":/dbresource/database.ico"));
    mainWindow->setWindowTitle("rockySQL");
    mainWindow->resize(1500, 800);

    this->initMenubar(mainWindow);
    this->initToolbar(mainWindow);
    this->initLayout(mainWindow);
    this->loginLayout(mainWindow);
}

void MainWindow::initMenubar(QMainWindow *mainWindow)
{
    menuBar = new QMenuBar(mainWindow);
    menuBar->setObjectName("menuBar");

    QAction *fileNewAction = new QAction("New");

    QMenu *fileMenu = new QMenu("File");
    fileMenu->setMinimumWidth(150);
    fileMenu->addAction(fileNewAction);

    QMenu *toolMenu = new QMenu("Tool");
    toolMenu->setMinimumWidth(150);

    QMenu *helpMenu = new QMenu("Help");
    helpMenu->setMinimumWidth(150);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(toolMenu);
    menuBar->addMenu(helpMenu);
    menuBar->setGeometry(0, 0, this->width(), 50);
    menuBar->setStyleSheet("background-color: #ccc");

    mainWindow->setMenuBar(menuBar);
}

void MainWindow::initToolbar(QMainWindow *mainWindow)
{
    //toolBar = new QToolBar(mainWindow);
}

void MainWindow::initLayout(QMainWindow *mainWindow)
{
    this->centralWidget = new QWidget(mainWindow);
    //mainWindow->setCentralWidget(centralWidget);
}

void MainWindow::loginLayout(QMainWindow *mainWindow)
{
    QGroupBox *groupBox = new QGroupBox(tr("Sign in"));

    QFormLayout *formLayout = new QFormLayout;

    QLineEdit *connectNameInput = new QLineEdit();
    QLineEdit *hostInput = new QLineEdit();
    QLineEdit *portInput = new QLineEdit();
    QLineEdit *usernameInput = new QLineEdit();
    QLineEdit *password = new QLineEdit();

    formLayout->addRow(("Name: "), connectNameInput);
    formLayout->addRow("Host: ", hostInput);
    formLayout->addRow(tr("Port: "), portInput);
    formLayout->addRow(tr("Username: "), usernameInput);
    formLayout->addRow(tr("Password: "), password);
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);

    groupBox->setLayout(formLayout);
    groupBox->setMaximumWidth(400);
    //groupBox->setAlignment(Qt::AlignRight);

    mainWindow->setCentralWidget(groupBox);
}



