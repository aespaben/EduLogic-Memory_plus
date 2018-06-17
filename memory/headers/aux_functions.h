/**
 * @file aux_functions.h
 * @author Angel España - GitHub aespaben
 * @author Patricia Daboin - GitHub apdaboin
 */

#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

#include <QDirIterator>
#include <QPixmap>
#include <cstdlib>
#include <time.h>
#include <list.H>
#include "headers/Card.h"
using namespace Designar;

/**
 * @brief Recibe un arreglo de números enteros (vacío) y le añade números enteros aleatorios sin repetir entre 0 y a_size
 * @param a Arreglo de números enteros
 * @param a_size Tamaño del arreglo a[].
 */
extern void random_pos_numbers_array(int a[], size_t a_size);


/**
 * @brief Aleatoriza las posiciones de los elementos de un arreglo cualquiera.
 * @param a Arreglo de cualquier tipo.
 * @param a_size Tamaño del arreglo a[].
 */
template<typename T>
extern void random_array(T a[], size_t a_size);

/**
 * @brief Aleatoriza las posiciones de los elementos de una lista simplemente enlazada.
 * @param a Lista simplemente enlazada.
 * @param a_size Tamaño de la lista a.
 */
extern void random_array(SLList<QString> *a, size_t a_size);

/**
 * @brief Aleatoriza las posiciones de los elementos de un arreglo de tipo Card*.
 * @param c Arreglo de tipo Card*.
 * @param c_size Tamaño del arreglo c.
 */
extern void random_array(Card *c[],size_t c_size);

/**
 * @brief Carga imágenes aleatorias a un arreglo de tipo QPixmap de acuerdo a una ubicación específica.
 * @param p Arreglo de imágenes (vacío).
 * @param p_size Tamaño del arreglo.
 * @param qs_dir Path del directorio donde se ubican las imágenes.
 */
extern void load_random_pixmaps_from_dir(QPixmap p[], size_t p_size, QString qs_dir);

/**
 * @brief Carga path's de imágenes aleatorias a una lista simplemente enlazada de tipo QPixmap de acuerdo a una ubicación específica.
 * @param sll_files Lista simplemente enlazada (puede estar vacía o no).
 * @param p_size Cantidad de imágenes a cargar.
 * @param qs_dir Path del directorio donde se ubican las imágenes.
 */
extern void load_random_pixmaps_from_dir(SLList<QString> *sll_files, size_t p_size, QString qs_dir);

#endif // AUX_FUNCTIONS_H
