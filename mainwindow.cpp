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
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal, this);
    mainSplitter->setFrameStyle(QFrame::NoFrame);
    mainSplitter->setHandleWidth(3);
    mainSplitter->setChildrenCollapsible(false);

    QWidget *leftWidget = new QWidget();
    leftWidget->setMaximumWidth(270);
    leftWidget->setMinimumWidth(150);
    mainSplitter->addWidget(leftWidget);

    QSplitter *rightSplitter = new QSplitter(Qt::Vertical, mainSplitter);
    QTextEdit *rightTopWidget = new QTextEdit("top right widget");
    QTextEdit *rightBottomWidget = new QTextEdit("right bottom widegt");
    rightSplitter->addWidget(rightTopWidget);
    rightSplitter->addWidget(rightBottomWidget);

    mainSplitter->addWidget(rightSplitter);

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
    toolBar = new QToolBar(mainWindow);

    QToolButton *structureTool = new QToolButton();
    structureTool->setIcon(QIcon(":/resource/images/toolbar-structure.png"));
    structureTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    structureTool->setText("structure");
    toolBar->addWidget(structureTool);

    QToolButton *contentTool = new QToolButton();
    contentTool->setIcon(QIcon(":/resource/images/toolbar-content.png"));
    contentTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    contentTool->setText("content");
    toolBar->addWidget(contentTool);

    QToolButton *tableInfoTool = new QToolButton();
    tableInfoTool->setIcon(QIcon(":/resource/images/toolbar-table-info.png"));
    tableInfoTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tableInfoTool->setText("table info");
    toolBar->addWidget(tableInfoTool);

    QToolButton *commandTool = new QToolButton();
    commandTool->setIcon(QIcon(":/resource/images/toolbar-command.png"));
    commandTool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    commandTool->setText("command");
    toolBar->addWidget(commandTool);

    addToolBar(toolBar);
}



