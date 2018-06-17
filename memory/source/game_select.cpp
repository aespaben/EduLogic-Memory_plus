/**
 * @file game_select.cpp
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */
#include "headers/game_select.h"
#include "ui_game_select.h"

game_select::game_select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game_select)
{
    ui->setupUi(this);
    descriptions[0] = "Selecciona un juego de la lista. Aquí podrás ver una breve descripción y a la izquierda una imagen sobre el juego.";
    descriptions[1] = "El juego de memoria convencional. Debes seleccionar pares de tarjetas que sean idénticas. Todas las imágenes aparecen tapadas y sólo se muestran al hacerles click.";
    descriptions[2] = "En esta modalidad, deberás seleccionar entre dos o más imágenes que guardan cierta relación lógica entre sí. Todas las imágenes son diferentes.";
    pix[0].load("://imgs/colorful-brain.png");
    pix[1].load(":/decks/imgs/deck_conventional.png");
    pix[2].load(":/decks/imgs/deck_relational.png");
}

/*************************************************************************************/
game_select::~game_select()
{
    delete ui;
}

/*************************************************************************************/
void game_select::on_comboBox_game_list_activated(int index)
{
    this->ui->label_game_img->setPixmap(this->pix[index]);
    this->ui->label_game_description->setText(this->descriptions[index]);
}

/*************************************************************************************/
void game_select::on_button_play_clicked()
{
    if(this->ui->comboBox_game_list->currentIndex() == 1)
    {
        Game_c *game_c = new Game_c();
        game_c->show();
        game_c->displayMainMenu();
        this->close();
    }

    if(this->ui->comboBox_game_list->currentIndex() == 2)
    {
        Game_r *game_r = new Game_r();
        game_r->show();
        game_r->displayMainMenu();
        this->close();
    }
}

/*************************************************************************************/
void game_select::on_button_back_clicked()
{
    (new MainWindow())->show();

    Game_c *c = new Game_c();
    delete c;

    this->close();
}
