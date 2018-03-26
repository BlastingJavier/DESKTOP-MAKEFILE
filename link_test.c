/**
*@brief Comprueba que el link funciona bien
*
*@file link_test.c
*@author FJNR & AMH & CMF & MLR
*@version 1.0aadsf
*@date 26/03/2018
*@copyright GNU Public License
*/


#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/**
 * @author Miguel Ángel Liaño y Alejandro Martin Herrera
 * @brief Se encarga de comprobar el correcto funcionamiento del módulo link
 * @param los agumentos del main (argc y argv)
 * @return, 0,1,2,3 o 4, dependiendo del numero de errores
 */
int main (int argc , char *argv[]){

  Link *link1 = NULL;
  Link *link2 = NULL;
  Link *link3 = NULL;

  link1 = link_create();
  if(link1 == NULL)
    return 1;

  link2 = link_create();
  if(link2 == NULL)
    return 1;

 link3 = link_create();
  if(link3 == NULL)
    return 1;

  link_set_name(link1,"enlace1");
  link_set_name(link2,"enlace2");
  link_set_name(link3,"enlace3");

  link_set_id(link1, 1);
  link_set_id(link2, 2);
  link_set_id(link3, 3);

  link_set_bool_state(link1, TRUE);
  link_set_bool_state(link2, FALSE);
  link_set_bool_state(link3, TRUE);

  link_destroy(link1);
  link_destroy(link2);
  link_destroy(link3);

  return 0;
}
