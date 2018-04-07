/**
 * @brief It tests object module
 *
 * @file object_test.c
 * @author Profesores Pprog
 * @version 2.0
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 17

/**
 * @brief Funcion principal de pruebas para el modulo Object.
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
        printf("Running all test for module Object:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_object_create();
    if (all || test == 2) test2_object_create();
    if (all || test == 3) test1_object_set_name();
    if (all || test == 4) test2_object_set_name();
    if (all || test == 5) test3_object_set_name();
    if (all || test == 6) test1_object_set_location();
    if (all || test == 7) test2_object_set_location();
    if (all || test == 8) test1_object_set_description();
    if (all || test == 9) test2_object_set_description();
    if (all || test == 10) test1_object_get_name();
    if (all || test == 11) test2_object_get_name();
    if (all || test == 12) test1_object_get_location();
    if (all || test == 13) test2_object_get_location();
    if (all || test == 14) test1_object_get_id();
    if (all || test == 15) test2_object_get_id();
    if (all || test == 16) test1_object_get_description();
    if (all || test == 17) test2_object_get_description();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_object_create() {
  int result = object_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_object_create() {
    Object *s;
    s = object_create(4);
    PRINT_TEST_RESULT(object_get_id(s) == 4);
}

void test1_object_set_name() {
    Object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_name(s, "Libro") == OK);
}

void test2_object_set_name() {
    Object *s = NULL;
    PRINT_TEST_RESULT(object_set_name(s, "Libro") == ERROR);
}

void test3_object_set_name() {
    Object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_name(s, NULL) == ERROR);
}

void test1_object_set_location() {
    Object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_location(s, 4) == OK);
}

void test2_object_set_location() {
    Object *s = NULL;
    PRINT_TEST_RESULT(object_set_location(s, 4) == ERROR);
}

void test1_object_set_description() {
    Object *s;
    s = object_create(1);
    PRINT_TEST_RESULT(object_set_description(s,"hola") == OK);
}

void test2_object_set_description() {
    Object *s = NULL;
    PRINT_TEST_RESULT(object_set_description(s,NULL) == ERROR);
}

void test1_object_get_name() {
    Object *s;
    s = object_create(1);
    object_set_name(s, "adios");
    PRINT_TEST_RESULT(strcmp(object_get_name(s), "adios") == 0);

}

void test2_object_get_name() {
    Object *s = NULL;
    PRINT_TEST_RESULT(object_get_name(s) == NULL);

}

void test1_object_get_location() {
    Object *s;
    s = object_create(1);
    /*Esto es porque en el object_create no iniciamos el campo Id location*/
    PRINT_TEST_RESULT(object_get_location(s) != NO_ID);

}

void test2_object_get_location() {
    Object *s;
    s = object_create(1);
    object_set_location(s,1);
    PRINT_TEST_RESULT(object_get_location(s) == 1);

}

void test1_object_get_id() {
    Object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_get_id(s) == 5);
}

void test2_object_get_id() {
    Object *s = NULL;
    PRINT_TEST_RESULT(object_get_id(s) == NO_ID);
}

void test1_object_get_description() {
    Object *s;
    s = object_create(5);
    object_set_description(s, "hola");
    PRINT_TEST_RESULT(strcmp(object_get_description(s),"hola")==0);
}

void test2_object_get_description() {
    Object *s = NULL;
    PRINT_TEST_RESULT(object_get_description(s) == NULL);
}
