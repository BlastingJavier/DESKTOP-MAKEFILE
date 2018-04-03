/**
*@brief Lleva a cabo el manejo de enlaces entre espacios
*
*@file link.c
*@author FJNR & AMH & CMF & MLR
*@version 1.0aadsf
*@date 26/03/2018
*@copyright GNU Public License
*/

#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "types.h"
#define LINKNAME 50

/**
 * @brief Estructura que lleva a cabo el manejo de enlaces entre espacios
*/

struct _Link {
  Id link_id;/*!<Identificador del enlace*/
  char link_name[LINKNAME];/*!<Nombre del enlace*/
  Id space1;/*!<Identificador de uno de los espacios enlazados*/
  Id space2;/*!<Identificador del otro espacio enlazado*/
  BOOL link_state;/*!<Si es FALSE, significa que el estado del enlace es abierto, si es TRUE, es cerrado*/
};



/**
 * @author Alejandro Martin
 * @brief Se encarga de crear el link,
   que será el encargado de manejar los enlaces
 * @return el link creado
 */
Link* link_create(Id id){
  Link *lk;

  lk = (Link*) malloc (sizeof(Link));
  if (lk == NULL){
    return NULL;
  }
  else {
    lk->link_name[0] = '\0';
    lk->link_id = id;
    lk->space1 = NO_ID;
    lk->space2 = NO_ID;
  }
  return lk;
}



 /**
  * @author Miguel Ángel Liaño
  * @brief Borra el enlace dado por argumento, liberando memoria
  * @param Link: puntero a Link.
  * @return status OK o ERROR.
  */
 void link_destroy(Link* link) {
   if (!link) {
     return;
   }

   free(link);
   return;
 }



 /**
  * @author Miguel Ángel Liaño
  * @brief Establece el nombre del enlace
  * @param Link: puntero a link, enlace donde establecer el nombre.
  * @param name: puntero a char, futuro nombre del enlace.
  * @return status OK o ERROR.
  */
 STATUS link_set_name(Link* link, char* name) {
   if (!link || !name) {
     return ERROR;
   }

   if (!strcpy(link->link_name, name)) {
     return ERROR;
   }

   return OK;
 }



 /**
  * @author Miguel Ángel Liaño
  * @brief Establece el identificador del enlace
  * @param : puntero a link,
  * @param id: campo de Id (identificador)
  * @return status OK o ERROR
  */
 STATUS link_set_id(Link *link, Id id) {
   if (!link || id == NO_ID) {
     return ERROR;
   }
   link->link_id = id;
   return OK;
 }



 /**
  * @author Alejandro Martin
  * @brief Establece el estado del enlace
  * @param : puntero a link.
  * @return status OK o ERROR
  */
 STATUS link_set_bool_state(Link *lk, BOOL tf) {
   if (lk == NULL){
     return ERROR;
   }
   lk->link_state = tf;
   return OK;
 }



 /**
  * @author Alejandro Martin
  * @brief Obtiene el estado del enlace
  * @param : puntero a link.
  * @return status OK o ERROR
  */
 BOOL link_get_bool_state(Link *lk) {
   if (lk == NULL){
     return FALSE;
   }
   return lk->link_state;
 }

 /**
  * @author Miguel Ángel Liaño
  * @brief Establece el identificador de uno de los espacios a enlazar
  * @param : puntero a link.
  * @param id: campo de Id (identificador)
  * @return status OK o ERROR o NO_ID
  */
 STATUS link_set_id_space1(Link *link, Id id){
   if (!link || id == NO_ID) {
     return ERROR;
   }
   link->space1 = id;
   return OK;
 }

 /**
  * @author Miguel Ángel Liaño
  * @brief Establece el identificador del otro espacio a enlazar
  * @param : puntero a link.
  * @param id: campo de Id (identificador)
  * @return status OK o ERROR o NO_ID
  */
 STATUS link_set_id_space2(Link *link, Id id) {
   if (!link || id == NO_ID) {
     return ERROR;
   }
   link->space2 = id;
   return OK;
 }



 /**
  * @author Miguel Ángel Liaño
  * @brief Devuelve el identificador del enlace dado por argumento
  * @param Link: puntero a link, contenedor del id devuelto.
  * @return id, el id del link o NO_ID si hay error.
  */
 Id link_get_id(Link* link) {
   if (!link) {
     return NO_ID;
   }
   return link->link_id;
 }



 /*
  * @author Miguel Ángel Liaño
  * @brief Devuelve el nombre del enlace dado por argumento
  * @param link: puntero a Link, donde se obtiene el nombre.
  * @return name, devuelve el nombre del enlace, en caso en contrario NULL
  */
 const char * link_get_name(Link* link) {
   if (!link) {
     return NULL;
   }
   return link->link_name;
 }


 /**
  * @author Miguel Ángel Liaño
  * @brief Devuelve el identificador de uno de los espacios enlazados
  * @param Link: puntero a link, contenedor del id del espacio devuelto.
  * @return id, el id del link o NO_ID si hay error.
  */
 Id link_get_id_space1(Link* link) {
   if (!link) {
     return NO_ID;
   }
   return link->space1;
 }



 /**
  * @author Miguel Ángel Liaño
  * @brief Devuelve el identificador del otro espacio enlazado
  * @param Link: puntero a link, contenedor del id del otro espacio devuelto.
  * @return id, el id del link o NO_ID si hay error.
  */
 Id link_get_id_space2(Link* link) {
   if (!link) {
     return NO_ID;
   }
   return link->space2;
 }



 /**
  * @author Alejandro Martin
  * @brief Imprimir por pantalla los campos de la estructura de datos de link
  * @param lk, puntero a link, para imprimirlo
  * @return OK o ERROR, ya que es de tipo STATUS
  */
 STATUS link_print(Link* lk) {
   if (lk == NULL){
     return ERROR;
   }

   fprintf(stdout,"El nombre del link es: %s", lk->link_name);
   fprintf(stdout,"\nEl id del link es: %ld", lk->link_id);
   fprintf(stdout,"\nId del primer espacio enlazado: %ld", lk->space1);
   fprintf(stdout,"\nId del segundo espacio enlazado: %ld", lk->space2);
   if(lk->link_state == 0 )
     fprintf(stdout,"\nEl estado del enlace es: %d (Cerrado)\n", lk->link_state);
   else
     fprintf(stdout,"\nEl estado del enlace es: %d (Abierto)\n", lk->link_state);


   return OK;
 }
