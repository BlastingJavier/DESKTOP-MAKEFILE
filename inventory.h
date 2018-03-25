#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

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
 * @return OK o ERROR status
 */
BOOL inventory_id_in(Inventory *inventory ,Id id_object);



/**
 * @author Francisco Nanclares
 * @brief Imprime los ids del inventario
 * @param pf , puntero a FILE (archivo de salida)
 * @param inventory , puntero a inventory
 * @return void
 */
void inventory_print(FILE*pf ,Inventory *inventory);

#endif
