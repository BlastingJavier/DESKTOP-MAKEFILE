#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "types.h"

/**
 * @author Miguel Ángel Liaño
 * @brief Se encarga de comprobar el correcto funcionamiento del módulo test
 * @param los agumentos del main (argc y argv)
 * @return, 0,1,2,3 o 4, dependiendo del error
 */
int main (int argc , char *argv[]){

    Set *set;
    Id id1=5;
    Id id2=7;

    set=set_create();

    set_push_id(set,id1);
    set_push_id(set,id2);
    set_push_id(set,1);
    set_push_id(set,3);
    set_push_id(set,8);
    if( set_ISFull(set) == TRUE){
      fprintf(stdout,"Conjunto lleno\n");
      set_print(set);
    }
    else{
      fprintf(stdout,"Conjunto no lleno\n");
      set_print(set);
    }

    set_pop_id(set);
    set_pop_id(set);
    id1 = set_get_specific_id(set,2);
    fprintf(stdout,"Id especifico: %ld\n", id1);

    set_delete_id(set,5);
    set_delete_id(set,7);
    set_delete_id(set,1);

    if(set_ISempty(set) == TRUE){
      fprintf(stdout,"Conjunto vacío\n");
      set_print(set);
    }
    else{
      fprintf(stdout,"Conjunto no vacío\n");
      set_print(set);
    }

    set_destroy(set);

  return 0;
}
