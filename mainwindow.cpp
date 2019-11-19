#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUi(this);

    this->fileHandle = new fileSystem();
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
    mainWindow->resize(1000, 600);

    this->initMenubar(mainWindow);
    this->initToolbar(mainWindow);
    this->initCentralWidget(mainWindow);
}

void MainWindow::initCentralWidget(QMainWindow *mainWindow)
{
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal, mainWindow);
    mainSplitter->setFrameStyle(QFrame::NoFrame);
    mainSplitter->setHandleWidth(3);
    mainSplitter->setChildrenCollapsible(false);

    QWidget *leftWidget = new QWidget(mainWindow);
    leftWidget->setStyleSheet("background: yellow");
    QWidget *rightWidget = this->loginLayout();

    mainSplitter->addWidget(leftWidget);
    mainSplitter->addWidget(rightWidget);

    setCentralWidget(mainSplitter);
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

QWidget* MainWindow::loginLayout()
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

    formLayout->addRow(("Name: "), connectNameInput);
    formLayout->addRow("Host: ", hostInput);
    formLayout->addRow(tr("Port: "), portInput);
    formLayout->addRow(tr("Username: "), usernameInput);
    formLayout->addRow(tr("Password: "), password);
    formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    formLayout->setContentsMargins(50, 100, 50, 50);

    groupBox->setLayout(formLayout);
    groupBox->setMinimumWidth(300);

    return groupBox;
}



