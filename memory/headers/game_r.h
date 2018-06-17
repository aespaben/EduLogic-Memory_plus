/**
 * @file game_r.h
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#ifndef GAME_R_H
#define GAME_R_H

#define SIZE(x)(sizeof(x)/sizeof(x[0]))

#include <QDesktopWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QThread>
#include <QList>
#include <QIcon>

#include <graph.H>
#include <list.H>

#include <cstdlib>
#include <time.h>

#include <headers/aux_functions.h>
#include <headers/Card.h>
#include <headers/button.h>
#include <headers/game_select.h>


using namespace Designar;
using Deck = Graph<Card*, int>;

/**
 * @brief Clase Game_r. Hereda de QGraphicsView
 */
class Game_r: public QGraphicsView
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase.
     * @param parent Puntero al QGraphicsView desde donde se creó esta instancia (NULL por defecto).
     */
    Game_r(QGraphicsView* parent = NULL);

    ~Game_r();

    /**
     * @brief Limpia la escena actual y muestra la escena de juego ganado.
     */
    void displayRestartGame();

    /**
     * @brief Limpia la escena actual y muestra la escena de juego perdido.
     */
    void displayGameOver();

public slots:
    /**
     * @brief Limpia la escena actual y muestra la escena del menú principal.
     */
    void displayMainMenu();

    /**
     * @brief Limpia la esena actual e inicia el juego.
     */
    void start();

    /**
     * @brief Compara las cartas seleccionadas (hacia arriba).
     */
    void compare_cards();

    /**
     * @brief Cierra el juego y libera la memoria utilizada.
     */
    void close_game();


private:
    QGraphicsScene* scene;
    QGraphicsTextItem *triesText;
    Deck deck;
    SLList<Deck::Node*> cards;
    size_t tries;
    size_t relations_found;
    size_t total_cards;

    /**
     * @brief Limpia la escena actual y libera la memoria utilizada por dicha escena de acuerdo al valor del parámetro.
     * @param free_memory Si es true, libera la memoria utilizada por todos los elementos del juego. Si es false, sólo limpia la escena actual.
     */
    void clean_scene(bool free_memory = false);
};

#endif // GAME_R_H
