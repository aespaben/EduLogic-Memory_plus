/**
 * @file button.cpp
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#include "headers/button.h"

Button::Button(QString img_standby, QString img_active, QGraphicsItem* parent):QGraphicsPixmapItem(parent)
{
    this->resting.load(img_standby);
    this->active.load(img_active);
    setPixmap(this->resting);
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        emit this->clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(this->active);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(this->resting);
}

void Button::setImages(QString img_standby, QString img_active)
{
    this->resting.load(img_standby);
    this->active.load(img_active);
    setPixmap(this->resting);
}
