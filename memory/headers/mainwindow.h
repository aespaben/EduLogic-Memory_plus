/**
 * @file mainwindow.h
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <headers/game_select.h>
#include <headers/about.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_start_clicked();

    void on_button_about_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
