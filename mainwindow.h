#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
