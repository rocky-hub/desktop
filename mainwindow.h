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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupUi(QMainWindow *mainWindow);
    void initMenubar(QMainWindow *mainWindow);
    void initToolbar(QMainWindow *mainWindow);
    void initLayout();
    void loginLayout();
    QMenuBar *menuBar;
    QMenu *menu[10];
    QAction *action;
    QToolBar *toolBar;
    QWidget *centralWidget;
    QGroupBox *formGroupBox;

};
#endif // MAINWINDOW_H
