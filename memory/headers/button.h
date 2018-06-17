/**
 * @file button.h
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */


#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>

/**
 * @brief Clase Button. Hereda de QObject y QGraphicsPixmapItem.
 */
class Button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    /**
     * @brief Constructor de la clase Button.
     * @param img_standby Path de la imagen del botón en reposo.
     * @param img_active Path de la imagen del botón activo (hover).
     * @param parent Puntero a QGraphicsItem a partir del cual fue creado el botón (por defecto es NULL).
     */
    Button(QString img_standby, QString img_active, QGraphicsItem *parent = NULL);

    /**
     * @brief Emite la señal clicked() siempre que se pulsa el botón izquierdo del ratón sobre una instancia de la clase Button.
     * @param event Puntero al evento generado por pulsar un botón del ratón.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @brief Cambia la imagen del botón a su forma activa siempre que el cursor pasa por encima de una instancia de la clase Button.
     * @param event Puntero al evento generado por pasar el cursor del ratón sobre una instancia de this.
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);

    /**
     * @brief Cambia la imagen del botón a su forma inactiva siempre que el cursor pasa por encima de una instancia de la clase Button.
     * @param event Puntero al evento generado por pasar el cursor del ratón sobre una instancia de this.
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    /**
     * @brief Carga las imágenes del botón.
     * @param img_standby Path de la imagen del botón en reposo.
     * @param img_active Path de la imagen del botón activo (hover).
     */
    void setImages(QString img_standby, QString img_active);

signals:
    void clicked();
private:
    QPixmap resting;
    QPixmap active;
};

#endif // BUTTON_H
