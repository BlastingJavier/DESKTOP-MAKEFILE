/**
*@brief Lleva a cabo las labores de manejo deeel inventario, contenedor de set (interfaz)
*
*@file inventory.h
*@author FJNR & AMH & CMF & MLR
*@version 1.0aadsf
*@date 26/03/2018
*@copyright GNU Public License
*/
#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdio.h>
#include <stdlib.h>
#include "set.h"


/**
 * @brief Estrucura que para las caracteristicas del inventario
*/
typedef struct _Inventory Inventory;

/**
 * @author Carlos Miret
 * @brief Se encarga de crear el inventario
 * @param id, de tipo Id
 * @return new_Inventory, que es el puntero a la estructura
 */
Inventory *inventory_create ();


/**
 * @author Francisco Nanclares
 * @brief Se encarga de liberar los recursos de inventory
 * @param inventory , puntero a Inventory
 * @return OK status
 */
STATUS inventory_destroy(Inventory *inventory);

/**
 * @author Francisco Nanclares
 * @brief Modifica el numero maximo de objetos en ele inventario
 * @param inventory , puntero a Inventory
 * @param nuevo_numero_max , int
 * @return OK o ERROR status
 */
STATUS inventory_set_max_objects(Inventory* inventory,int nuevo_numero_max);



/**
 * @author Francisco Nanclares
 * @brief Mete un objeto dentro del inventario
 * @param inventory , puntero a Inventory
 * @param id_object ,Id
 * @return OK o ERROR status
 */
STATUS inventory_add_object(Inventory *inventory ,Id id_object);



/**
 * @author Francisco Nanclares
 * @brief Comprueba si el id de un objeto esta en ele inventario
 * @param inventory , puntero a Inventory
 * @param id_object ,Id
 * @return FALSE o TRUE status
 */
BOOL inventory_id_in(Inventory *inventory ,Id id_object);



/**
 * @author Francisco Nanclares
 * @brief Coje un id del inventario haciendo uso de un conjunto
 * @param inventory , puntero a Inventory
 * @param numero_max_objects_aux,int
 * @return Id , id_aux(variable local) o NO_ID
 */
Id inventory_get_specific_id(Inventory *inventory,int numero_max_objects_aux);



/**
 * @author Francisco Nanclares
 * @brief Elimina un objeto del inventario
 * @param inventory , puntero a Inventory
 * @param id_object ,Id
 * @return OK o ERROR status
 */
STATUS inventory_delete_object(Inventory *inventory , Id id_object);



/**
 * @author Francisco Nanclares
 * @brief coge un objeto del inventario
 * @param inventory , puntero a Inventory
 * @return id , ID
 */
Id inventory_pop_a_object(Inventory* inventory);


/**
 * @author Francisco Nanclares
 * @brief Obtiene el top actual del set que se utiliza como inventario
 * @param inventory , puntero a Inventory
 * @return int 0 o top (tipo int)
 */
int inventory_get_actual_set_top(Inventory *inventory);



/**
 * @author Francisco Nanclares
 * @brief Obtiene el set del inventario
 * @param inventory , puntero a Inventory
 * @return un set
 */
Set * inventory_get_set(Inventory* inventory);



/**
 * @author Francisco Nanclares
 * @brief Imprime los ids del inventario
 * @param pf , puntero a FILE (archivo de salida)
 * @param inventory , puntero a inventory
 * @return void
 */
void inventory_print(FILE*pf ,Inventory *inventory);

#endif
