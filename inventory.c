#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "inventory.h"



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
  new_Inventory->set = NULL;

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
 * @return OK o ERROR status
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
