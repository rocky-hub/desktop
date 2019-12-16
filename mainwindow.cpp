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

    mainWindow->setWindowIcon(QIcon(":/resource/images/database.ico"));
    mainWindow->setWindowTitle("rockySQL");
    mainWindow->resize(1200, 800);

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

    Login *loginUi = new Login(mainWindow);

    QWidget *leftWidget = loginUi->setListWidget();
    QWidget *rightWidget = loginUi->setLoginUi();

    mainSplitter->addWidget(leftWidget);
    mainSplitter->addWidget(rightWidget);

    setCentralWidget(mainSplitter);
}

void MainWindow::reloadCentralWidget()
{
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->setFrameStyle(QFrame::NoFrame);
    mainSplitter->setHandleWidth(3);
    mainSplitter->setChildrenCollapsible(false);

    mainSplitter->addWidget(this->leftWidget());

    QSplitter *rightSplitter = new QSplitter(Qt::Vertical, mainSplitter);

    rightSplitter->addWidget(this->rightTopWidget());
    rightSplitter->addWidget(this->rightButtomWidget());

    mainSplitter->addWidget(rightSplitter);

    setCentralWidget(mainSplitter);
    reloadDatabaseTool();
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
    toolBar = new QToolBar(mainWindow);
    toolBar->setMovable(false);

    databaseTool = new QComboBox;
    databaseTool->setMinimumWidth(250);
    databaseTool->addItem("Chose Database");
    toolBar->addWidget(databaseTool);

    structureTool = new QToolButton();
    structureTool->setIcon(QIcon(":/resource/images/toolbar-structure.png"));
    structureTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    structureTool->setText("structure");
    toolBar->addWidget(structureTool);

    contentTool = new QToolButton();
    contentTool->setIcon(QIcon(":/resource/images/toolbar-content.png"));
    contentTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    contentTool->setText("content");
    toolBar->addWidget(contentTool);

    tableInfoTool = new QToolButton();
    tableInfoTool->setIcon(QIcon(":/resource/images/toolbar-table-info.png"));
    tableInfoTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tableInfoTool->setText("table info");
    toolBar->addWidget(tableInfoTool);

    commandTool = new QToolButton();
    commandTool->setIcon(QIcon(":/resource/images/toolbar-command.png"));
    commandTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    commandTool->setText("command");
    toolBar->addWidget(commandTool);

    addToolBar(toolBar);

    connect(databaseTool, SIGNAL(currentTextChanged(const QString &)), this, SLOT(databaseToolChange(const QString &)));
    connect(structureTool, SIGNAL(clicked()), this, SLOT(structToolClick()));
    connect(contentTool, SIGNAL(clicked()), this, SLOT(contentToolClick()));
    connect(tableInfoTool, SIGNAL(clicked()), this, SLOT(tableInfoToolClick()));
    connect(commandTool, SIGNAL(clicked()), this, SLOT(commandToolClick()));
}

void MainWindow::reloadDatabaseTool()
{
    Mysql& mysqlHandle = Mysql::getInstance();
    QVector<QString> databases = mysqlHandle.database();
    for (int i = 0; i < databases.size(); ++i) {
        databaseTool->addItem(databases[i]);
    }
}

void MainWindow::structToolClick()
{
    resetToolActive();
    structureTool->setStyleSheet("background-color:#c6c6c6");
}

void MainWindow::contentToolClick()
{
    resetToolActive();
    contentTool->setStyleSheet("background-color:#c6c6c6");
}

void MainWindow::tableInfoToolClick()
{
    resetToolActive();
    tableInfoTool->setStyleSheet("background-color:#c6c6c6");
}

void MainWindow::commandToolClick()
{
    resetToolActive();
    commandTool->setStyleSheet("background-color:#c6c6c6");
}

void MainWindow::resetToolActive()
{
    structureTool->setStyleSheet("");
    contentTool->setStyleSheet("");
    tableInfoTool->setStyleSheet("");
    commandTool->setStyleSheet("");
}

void MainWindow::databaseToolChange(const QString& database)
{
    Mysql& mysqlHandle = Mysql::getInstance();
    mysqlHandle.currentDatabase = database;

    QVector<QString> tables = mysqlHandle.table(mysqlHandle.currentDatabase);
    if (!mysqlHandle.currentDatabase.isEmpty()) {
        tableListWidget->clear();
        for (int j = 0; j < tables.size(); ++j) {
            tableListWidget->addItem(new QListWidgetItem(QIcon(":/resource/images/table-small-square.png"), tables[j]));
        }
    }
}

QWidget *MainWindow::leftWidget()
{
    Mysql& mysqlHandle = Mysql::getInstance();
    QVector<QString> databases = mysqlHandle.database();

    tableListWidget = new QListWidget();
    tableListWidget->setMaximumWidth(270);
    tableListWidget->setMidLineWidth(170);

    QVector<QString> tables = mysqlHandle.table(mysqlHandle.currentDatabase);
    if (!mysqlHandle.currentDatabase.isEmpty()) {
        tableListWidget->clear();
        for (int j = 0; j < tables.size(); ++j) {
            tableListWidget->addItem(new QListWidgetItem(QIcon(":/resource/images/table-small-square.png"), tables[j]));
        }
    }

    connect(tableListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(tableSingleClicked(QListWidgetItem*)));

    return tableListWidget;
}

QWidget *MainWindow::rightWidget()
{
    QWidget *obj = new QWidget();

    return obj;
}

QWidget *MainWindow::rightTopWidget()
{
    QTextEdit *rightTopWidget = new QTextEdit("top right widget");

    return rightTopWidget;

}

QWidget *MainWindow::rightButtomWidget()
{
    QTableWidget *tableWidget = new QTableWidget(10, 5);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->setItem(0,0,new QTableWidgetItem("Jan"));
    tableWidget->setItem(1,0,new QTableWidgetItem("Feb"));
    tableWidget->setItem(2,0,new QTableWidgetItem("Mar"));

    return tableWidget;
}

QWidget *MainWindow::tableWidget()
{
    QWidget *obj = new QWidget();

    return obj;
}

QWidget *MainWindow::commandWidget()
{
    QWidget *obj = new QWidget();

    return obj;
}

void MainWindow::tableSingleClicked(QListWidgetItem* item)
{
    Mysql& mysqlHandle = Mysql::getInstance();
    mysqlHandle.currenctTable = item->text();

    mysqlHandle.value();
    //qDebug() << item->text();
}



