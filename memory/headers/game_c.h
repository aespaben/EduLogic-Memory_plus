/**
 * @file game_c.h
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#ifndef GAME_C_H
#define GAME_C_H

#define SIZE(x)(sizeof(x)/sizeof(x[0]))

#include <QDesktopWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QThread>
#include <QList>
#include <QIcon>
#include <QDialog>

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
 * @brief Clase Game_c. Hereda de QGraphicsView
 */
class Game_c: public QGraphicsView
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase.
     * @param parent Puntero al QGraphicsView desde donde se creó esta instancia (NULL por defecto).
     */
    Game_c(QGraphicsView* parent = NULL);

    ~Game_c();

    /**
     * @brief Limpia la escena actual y muestra la escena de juego ganado.
     */
    void displayRestartGame();


public slots:
    /**
     * @brief Limpia la escena actual y muestra la escena del menú principal.
     */
    void displayMainMenu();

    /**
     * @brief Limpia la escena actual y muestra la escena de selección de dificultad.
     */
    void difficultySelection();

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

    /**
     * @brief Modifica el número de pares de cartas a 3.
     */
    void easy();

    /**
     * @brief Modifica el número de pares de cartas a 5.
     */
    void medium();

    /**
     * @brief Modifica el número de pares de cartas a 7.
     */
    void hard();

private:
    QGraphicsScene* scene;
    QTimer *timer;
    QGraphicsTextItem *triesText;
    Deck deck;
    SLList<Deck::Node*> cards;
    size_t tries;
    size_t pairs_found;
    size_t total_cards;
    size_t difficulty;

    /**
     * @brief Limpia la escena actual y libera la memoria utilizada por dicha escena de acuerdo al valor del parámetro.
     * @param free_memory Si es true, libera la memoria utilizada por todos los elementos del juego. Si es false, sólo limpia la escena actual.
     */
    void clean_scene(bool free_memory = false);
};

#endif // GAME_C_H
