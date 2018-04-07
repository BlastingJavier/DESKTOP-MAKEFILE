/**
 * @brief It tests set module
 *
 * @file set_test.c
 * @author Francisco Javier Nanclares Rodriguez
 * @version 2.0
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 16

/**
 * @brief Funcion principal de pruebas para el modulo Set.
 *
 * Dos modos de ejecucion:
 *   1.-Si se ejecuta sin parametros se ejecutan todas las pruebas
 *   2.-Si se ejecuta con un numero entre 1 y el numero de pruebas solo ejecuta
 *      la prueba indicada
 *
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Set:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_set_create();
    if (all || test == 2) test1_set_push_id();
    if (all || test == 3) test2_set_push_id();
    if (all || test == 4) test1_set_pop_id();
    if (all || test == 5) test2_set_pop_id();
    if (all || test == 6) test1_set_get_specific_id();
    if (all || test == 7) test2_set_get_specific_id();
    if (all || test == 8) test1_set_get_top();
    if (all || test == 9) test2_set_get_top();
    if (all || test == 10) test1_set_ISEMPTY();
    if (all || test == 11) test2_set_ISEMPTY();
    if (all || test == 12) test1_set_ISFull();
    if (all || test == 13) test2_set_ISFull();
    if (all || test == 14) test1_set_delete_id();
    if (all || test == 15) test2_set_delete_id();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_set_create() {
  int result = set_create()!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test1_set_push_id() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_push_id(s, 4) == OK);
}

void test2_set_push_id() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_push_id(s, 4) == ERROR);
}

void test1_set_pop_id() {
    Set *s;
    s = set_create();
    set_push_id(s,4);
    PRINT_TEST_RESULT(set_pop_id(s) == 4);
}

void test2_set_pop_id() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_pop_id(s) == NO_ID);
}

void test1_set_get_specific_id() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_get_specific_id(s,1) == NO_ID);
}

void test2_set_get_specific_id() {
    Set *s = NULL;
    s = set_create();
    set_push_id(s,1);
    /*Numero 1 del array de ids*/
    PRINT_TEST_RESULT(set_get_specific_id(s,0) == 1);
}

void test1_set_get_top() {
    Set *s;
    s = set_create();
    set_push_id(s,2);
    PRINT_TEST_RESULT(set_get_top(s) == 1);
}

void test2_set_get_top() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_get_top(s) == 0);
}

void test1_set_ISEMPTY() {
    Set *s;
    s = set_create();
    set_push_id(s,1);
    PRINT_TEST_RESULT(set_ISempty(s) == FALSE);
}

void test2_set_ISEMPTY() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_ISempty(s) == TRUE);
}

void test1_set_ISFull() {
    Set *s;
    int i;
    s = set_create();
    for (i=0;i<MAX_ID;i++){
      set_push_id(s,i);
    }
    PRINT_TEST_RESULT(set_ISFull(s) == TRUE);
}

void test2_set_ISFull() {
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_ISFull(s) == FALSE);
}

void test1_set_delete_id() {
    Set *s;
    s = set_create();
    set_push_id(s,5);
    PRINT_TEST_RESULT(set_delete_id(s,5) == OK);
}

void test2_set_delete_id() {
    Set *s;
    s = set_create();
    set_push_id(s,5);
    PRINT_TEST_RESULT(set_delete_id(s,1) == ERROR);
}
