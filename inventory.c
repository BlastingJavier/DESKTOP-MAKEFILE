/**
*@brief Lleva a cabo las labores de manejo deeel inventario, contenedor de set
*
*@file inventory.c
*@author FJNR & AMH & CMF & MLR
*@version 1.0aadsf
*@date 26/03/2018
*@copyright GNU Public License
*/
#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "inventory.h"


/**
 * @brief Estrucura que para las caracteristicas del inventario
*/
struct _Inventory {
  Set *set;/*!<Puntero a set (conjunto de identificadores)*/
  int numero_max_objects;/*!<Numero maximo de objetos*/
};



/**
 * @author Carlos Miret
 * @brief Se encarga de crear el inventario
 * @param id, de tipo Id
 * @return new_Inventory, que es el puntero a la estructura
 */
Inventory* inventory_create(){
  Inventory *new_Inventory;
  new_Inventory = (Inventory*)malloc(sizeof(Inventory));

  if (new_Inventory == NULL){
    return NULL;
  }

  new_Inventory->numero_max_objects = 0;
  new_Inventory->set = set_create();

  return new_Inventory;
}



/**
 * @author Francisco Nanclares
 * @brief Se encarga de liberar los recursos de inventory
 * @param inventory , puntero a Inventory
 * @return OK status
 */
STATUS inventory_destroy(Inventory *inventory){
  set_destroy(inventory->set);
  free(inventory);

  return OK;
}



/**
 * @author Francisco Nanclares
 * @brief Modifica el numero maximo de objetos en ele inventario
 * @param inventory , puntero a Inventory
 * @param nuevo_numero_max , int
 * @return OK o ERROR status
 */
STATUS inventory_set_max_objects(Inventory* inventory,int nuevo_numero_max){
  if (!inventory || nuevo_numero_max <0){
    return ERROR;
  }

  inventory->numero_max_objects = nuevo_numero_max;

  return OK;
}



/**
 * @author Francisco Nanclares
 * @brief Mete un objeto dentro del inventario
 * @param inventory , puntero a Inventory
 * @param id_object ,Id
 * @return OK o ERROR status
 */
STATUS inventory_add_object(Inventory *inventory ,Id id_object){
  if (!inventory || id_object == NO_ID){
    return ERROR;
  }
  if (set_push_id(inventory->set,id_object)==ERROR){
    return ERROR;
  }

  return OK;
}



/**
 * @author Francisco Nanclares
 * @brief Comprueba si el id de un objeto esta en el inventario
 * @param inventory , puntero a Inventory
 * @param id_object ,Id
 * @return FALSE o TRUE status
 */
BOOL inventory_id_in(Inventory *inventory ,Id id_object){
  int i;
  int top;
  if (!inventory || id_object == NO_ID){
    return ERROR;
  }
  /*Cogemos el top del set*/
  top = set_get_top(inventory->set);

  for (i=0;i<top;i++){
    /*Comprobamos que el id esta en el set*/
    if (set_get_specific_id(inventory->set,i) == id_object){
      return TRUE;
    }
  }

  return FALSE;
}



/**
 * @author Francisco Nanclares
 * @brief Coje un id del inventario haciendo uso de un conjunto
 * @param inventory , puntero a Inventory
 * @param numero_max_objects_aux,int
 * @return Id , id_aux(variable local) o NO_ID
 */
Id inventory_get_specific_id(Inventory *inventory,int numero_max_objects_aux){
  Id id_aux;
  if (inventory == NULL|| numero_max_objects_aux < 0 || (numero_max_objects_aux > set_get_top(inventory->set)) || set_ISempty(inventory->set) == TRUE){
    return NO_ID;
  }
  id_aux = set_get_specific_id(inventory->set,numero_max_objects_aux);


  return id_aux;
}



/**
 * @author Francisco Nanclares
 * @brief Elimina un objeto del inventario
 * @param inventory , puntero a Inventory
 * @param id_object ,Id
 * @return OK o ERROR status
 */
STATUS inventory_delete_object(Inventory *inventory , Id id_object){
  if (!inventory || id_object == NO_ID){
    return ERROR;
  }
  if (set_delete_id(inventory->set,id_object)==ERROR){
    return ERROR;
  }

  return OK;
}



/**
 * @author Francisco Nanclares
 * @brief coge un objeto del inventario
 * @param inventory , puntero a Inventory
 * @return id , ID
 */
Id inventory_pop_a_object(Inventory* inventory){
  Id id_aux;
  if (!inventory){
    return NO_ID;
  }
  id_aux = set_pop_id(inventory->set);
  if (id_aux == NO_ID){
    return NO_ID;
  }
  return id_aux;
}



/**
 * @author Francisco Nanclares
 * @brief Obtiene el top actual del set que se utiliza como inventario
 * @param inventory , puntero a Inventory
 * @return int 0 o top (tipo int)
 */
int inventory_get_actual_set_top(Inventory *inventory){
  int top;
  if (!inventory){
    return 0;
  }
  top = set_get_top(inventory->set);
  if (top == 0){
    return 0;
  }

  return top;
}



/**
 * @author Francisco Nanclares
 * @brief Obtiene el set del inventario
 * @param inventory , puntero a Inventory
 * @return un set
 */
Set * inventory_get_set(Inventory* inventory){
  if (!inventory){
    return NULL;
  }

  return inventory->set;
}



/**
 * @author Francisco Nanclares
 * @brief Imprime los ids del inventario
 * @param pf , puntero a FILE (archivo de salida)
 * @param inventory , puntero a inventory
 * @return void
 */
void inventory_print(FILE*pf ,Inventory *inventory){
  int i;
  int top;
  if (!inventory || pf == NULL){
    return;
  }
  top = set_get_top(inventory->set);

  for (i=0;i<top;i++){
    fprintf(pf,"Inventory --> %ld",set_get_specific_id(inventory->set,i));
  }
  return;
}
