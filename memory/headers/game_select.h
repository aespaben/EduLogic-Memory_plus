/**
 * @file game_select.h
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */
#ifndef GAME_SELECT_H
#define GAME_SELECT_H

#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/game_c.h"
#include "headers/game_r.h"

namespace Ui {
class game_select;
}

class game_select : public QDialog
{
    Q_OBJECT

public:
    explicit game_select(QWidget *parent = 0);
    ~game_select();

private slots:
    void on_comboBox_game_list_activated(int index);

    void on_button_play_clicked();

    void on_button_back_clicked();

private:
    Ui::game_select *ui;
    QString descriptions[3];
    QPixmap pix[3];
};

#endif // GAME_SELECT_H
