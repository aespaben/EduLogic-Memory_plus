/**
 * @file Card.h
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#ifndef CARD_H
#define CARD_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/**
 * @brief Clase Card. Hereda de QObject y QGraphicsPixmapItem.
 */
class Card:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QPixmap image[2];
    QString image_name[2];
    int card_id;
    bool card_up;

public:

    /**
     * @brief Constructor de la clase.
     * @param dorsal Cadena de texto con el path de la imagen dorsal de la carta.
     * @param up Cadena de texto con el path de la imagen frontal de la carta.
     * @param id Número que identifica la carta.
     * @param parent
     */
    Card(QString dorsal, QString up, int id = -1, QGraphicsItem *parent = NULL)
        :QGraphicsPixmapItem(parent), card_id(id)
    {
        this->image[0].load(dorsal);
        this->image[1].load(up);
        this->image_name[0] = dorsal;
        this->image_name[1] = up;
        this->card_up = false;
        setPixmap(this->image[0]);
    }

    /**
     * @brief Modifica las imágenes de la carta.
     * @param dorsal Cadena de texto con el path de la imagen dorsal de la carta.
     * @param up Cadena de texto con el path de la imagen frontal de la carta.
     * @param id Número que identifica la carta.
     */
    void set_card(QString dorsal, QString up, int id)
    {
        this->image[0].load(dorsal);
        this->image[1].load(up);
        this->image_name[0] = dorsal;
        this->image_name[1] = up;
        this->card_id = id;
    }

    /**
     * @brief Coloca al frente la imagen frontal de la carta.
     */
    void show_card()
    {
        this->card_up = true;
        this->setPixmap(this->image[1]);
    }

    /**
     * @brief Coloca al frente la imagen dorsal de la carta.
     */
    void hide_card()
    {
        this->card_up = false;
        this->setPixmap(this->image[0]);
    }

    /**
     * @brief Retorna la imagen dorsal de la carta.
     * @return Imagen dorsal de la carta.
     */
    QPixmap get_dorsal()
    {
        return this->image[0];
    }

    /**
     * @brief Retorna la imagen frontal de la carta.
     * @return Imagen frontal de la carta.
     */
    QPixmap get_front()
    {
        return this->image[1];
    }

    /**
     * @brief Retorna el id de la carta.
     * @return id de la carta.
     */
    int get_id()
    {
        return this->card_id;
    }

    /**
     * @brief Retorna el path de la imagen de la carta según un índice (0 o 1).
     * @param index Índice del arreglo que contiene los path's de las imágenes.
     * @return Path de la imagen si el índice es 0 o 1.
     * @return Cadena vacia si el índice es diferente de 0 y 1.
     */
    QString get_name(size_t index)
    {
        if(index < 2)
            return this->image_name[index];

        return QString();
    }

    /**
     * @brief Modifica el id de la carta.
     * @param id Número que identifica a la carta.
     */
    void set_id(int id)
    {
        this->card_id = id;
    }

    /**
     * @brief Comprueba si la carta está hacia arriba (frontal) o hacia abajo (dorsal).
     * @return true si la carta está hacia arriba.
     * @return false si la carta está hacia abajo.
     */
    bool is_up()
    {
        return this->card_up;
    }

    ~Card(){}


protected:

    /**
     * @brief Muestra u oculta la carta cuando recibe un click con el botón izquierdo del ratón.
     * @param event Evento que se genera al hacer click con el ratón sobre la carta.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton and not this->is_up())
            this->show_card();

        else if(event->button() == Qt::LeftButton and this->is_up())
            this->hide_card();

    }
};

#endif // CARD_H
