#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QFormLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QWidget>
#include <QVBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QToolButton>
#include <QComboBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTextEdit>
#include <QDebug>
#include <QStringList>
#include <QList>
#include <QHeaderView>
#include <QVector>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTableView>
#include <QSqlTableModel>
#include "filesystem.h"
#include "login.h"
#include "mysql.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupUi(QMainWindow *mainWindow);
    void initMenubar(QMainWindow *mainWindow);
    void initToolbar(QMainWindow *mainWindow);
    void initCentralWidget(QMainWindow *mainWindow);
    void reloadDatabaseTool();
    void setLeftWidget();
    void setRightWidget();
    void setRightTopWidget();
    void setRightButtomWidget();
    QTableView* setTableWidget();
    void setCommandWidget();
    QWidget *loginLayout();
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QGroupBox *formGroupBox;
    FileSystem *fileHandle;
    QWidget *loginUi;
    Mysql *mysqlHandle;
    QToolButton *structureTool;
    QToolButton *contentTool;
    QToolButton *tableInfoTool;
    QToolButton *commandTool;
    QComboBox *databaseTool;
    QListWidget *tableListWidget;
    QSplitter *mainSplitter;
    QWidget *rightWidget;
    QWidget *rightTopWidget;
    QWidget *rightBottomWidget;
    QTableView *table;

    enum Tools {structure, content, info, command};
    qint8 currentToolName = content;
signals:

public slots:
    void reloadCentralWidget();
    void structToolClick();
    void contentToolClick();
    void tableInfoToolClick();
    void commandToolClick();
    void resetToolActive();
    void databaseToolChange(const QString& database);
    void tableSingleClicked(QListWidgetItem *item);
};
#endif // MAINWINDOW_H
