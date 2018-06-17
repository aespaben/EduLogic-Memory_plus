/**
 * @file mainwindow.cpp
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */
#include "headers/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                )
            );
}

/*************************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/*************************************************************************************/
void MainWindow::on_button_start_clicked()
{
    (new game_select())->open();
    this->close();
}

/*************************************************************************************/
void MainWindow::on_button_about_clicked()
{
    about ab;
    ab.exec();
}
