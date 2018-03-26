/**
*@brief Lleva a cabo el manejo de enlaces entre espacios
*
*@file link.h
*@author FJNR & AMH & CMF & MLR
*@version 1.0aadsf
*@date 26/03/2018
*@copyright GNU Public License
*/


#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"


/**
 * @brief Estructura que lleva a cabo el manejo de enlaces entre espacios
*/

typedef struct _Link Link;



/**
 * @author Alejandro Martin
 * @brief Se encarga de crear el link,
   que será el encargado de manejar los enlaces
 * @return el link creado
 */
Link *link_create();



/**
 * @author Miguel Ángel Liaño
 * @brief Borra el enlace dado por argumento, liberando memoria
 * @param Link: puntero a Link.
 * @return status OK o ERROR.
 */
void link_destroy(Link* link);



/**
 * @author Miguel Ángel Liaño
 * @brief Establece el nombre del enlace
 * @param Link: puntero a link, enlace donde establecer el nombre.
 * @param name: puntero a char, futuro nombre del enlace.
 * @return status OK o ERROR.
 */
STATUS link_set_name(Link* link, char* name);



/**
 * @author Miguel Ángel Liaño
 * @brief Establece el identificador del enlace
 * @param : puntero a link,
 * @param id: campo de Id (identificador)
 * @return status OK o ERROR
 */
STATUS link_set_id(Link *link, Id id);



/**
 * @author Alejandro Martin
 * @brief Establece el estado del enlace
 * @param : puntero a link.
 * @return status OK o ERROR
 */
STATUS link_set_bool_state(Link *lk, BOOL tf);



/**
 * @author Alejandro Martin
 * @brief Obtiene el estado del enlace
 * @param : puntero a link.
 * @return status OK o ERROR
 */
BOOL link_get_bool_state(Link *lk);



/**
 * @author Miguel Ángel Liaño
 * @brief Establece el identificador de uno de los espacios a enlazar
 * @param : puntero a link.
 * @param id: campo de Id (identificador)
 * @return status OK o ERROR o NO_ID
 */
STATUS link_set_id_space1(Link *link, Id id);



/**
 * @author Miguel Ángel Liaño
 * @brief Establece el identificador del otro espacio a enlazar
 * @param : puntero a link.
 * @param id: campo de Id (identificador)
 * @return status OK o ERROR o NO_ID
 */
STATUS link_set_id_space2(Link *link, Id id);



/**
 * @author Miguel Ángel Liaño
 * @brief Devuelve el identificador del enlace dado por argumento
 * @param Link: puntero a link, contenedor del id devuelto.
 * @return id, el id del link o NO_ID si hay error.
 */
Id link_get_id(Link* link);



/*
 * @author Miguel Ángel Liaño
 * @brief Devuelve el nombre del enlace dado por argumento
 * @param link: puntero a Link, donde se obtiene el nombre.
 * @return name, devuelve el nombre del enlace, en caso en contrario NULL
 */
const char * link_get_name(Link* link);



/**
 * @author Miguel Ángel Liaño
 * @brief Devuelve el identificador de uno de los espacios enlazados
 * @param Link: puntero a link, contenedor del id del espacio devuelto.
 * @return id, el id del link o NO_ID si hay error.
 */
Id link_get_id_space1(Link* link);



/**
 * @author Miguel Ángel Liaño
 * @brief Devuelve el identificador del otro espacio enlazado
 * @param Link: puntero a link, contenedor del id del otro espacio devuelto.
 * @return id, el id del link o NO_ID si hay error.
 */
Id link_get_id_space2(Link* link);



/**
 * @author Alejandro Martin
 * @brief Imprimir por pantalla los campos de la estructura de datos de link
 * @param lk, puntero a link, para imprimirlo
 * @return OK o ERROR, ya que es de tipo STATUS
 */
STATUS link_print(Link* lk);

#endif
