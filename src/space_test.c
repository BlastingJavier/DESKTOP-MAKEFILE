/**
 * @brief It tests space module
 *
 * @file space_test.c
 * @author Profesores Pprog
 * @version 2.0
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "space_test.h"
#include "test.h"


#define MAX_TESTS 49

/**
 * @brief Funcion principal de pruebas para el modulo Space.
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
        printf("Running all test for module Space:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_space_create();
    if (all || test == 2) test2_space_create();
    if (all || test == 3) test1_space_set_name();
    if (all || test == 4) test2_space_set_name();
    if (all || test == 5) test3_space_set_name();
    if (all || test == 6) test1_space_set_link_north();
    if (all || test == 7) test2_space_set_link_north();
    if (all || test == 8) test1_space_set_link_south();
    if (all || test == 9) test2_space_set_link_south();
    if (all || test == 10) test1_space_set_link_east();
    if (all || test == 11) test2_space_set_link_east();
    if (all || test == 12) test1_space_set_link_west();
    if (all || test == 13) test2_space_set_link_west();
    if (all || test == 14) test1_space_set_gdesc1();
    if (all || test == 15) test2_space_set_gdesc1();
    if (all || test == 16) test1_space_set_gdesc2();
    if (all || test == 17) test2_space_set_gdesc2();
    if (all || test == 18) test1_space_set_gdesc3();
    if (all || test == 19) test2_space_set_gdesc3();
    if (all || test == 20) test1_space_set_description();
    if (all || test == 21) test2_space_set_description();
    if (all || test == 22) test1_space_delete_object();
    if (all || test == 23) test2_space_delete_object();
    if (all || test == 24) test1_space_add_object();
    if (all || test == 25) test2_space_add_object();
    if (all || test == 26) test1_space_get_objects();
    if (all || test == 27) test2_space_get_objects();
    if (all || test == 28) test1_space_check_in_space();
    if (all || test == 29) test2_space_check_in_space();
    if (all || test == 30) test1_space_get_name();
    if (all || test == 31) test2_space_get_name();
    if (all || test == 32) test1_space_get_link_north();
    if (all || test == 33) test2_space_get_link_north();
    if (all || test == 34) test1_space_get_link_south();
    if (all || test == 35) test2_space_get_link_south();
    if (all || test == 36) test1_space_get_link_east();
    if (all || test == 37) test2_space_get_link_east();
    if (all || test == 38) test1_space_get_link_west();
    if (all || test == 39) test2_space_get_link_west();
    if (all || test == 40) test1_space_get_id();
    if (all || test == 41) test2_space_get_id();
    if (all || test == 42) test1_space_get_gdesc1();
    if (all || test == 43) test2_space_get_gdesc1();
    if (all || test == 44) test1_space_get_gdesc2();
    if (all || test == 45) test2_space_get_gdesc2();
    if (all || test == 46) test1_space_get_gdesc3();
    if (all || test == 47) test2_space_get_gdesc3();
    if (all || test == 48) test1_space_get_description();
    if (all || test == 49) test2_space_get_description();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_space_create() {
  int result = space_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_space_create() {
    Space *s;
    s = space_create(4);
    PRINT_TEST_RESULT(space_get_id(s) == 4);
}

void test1_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
}

void test2_space_set_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
}

void test1_space_set_link_north() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_link_north(s, 4) == OK);
}

void test2_space_set_link_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_link_north(s, 4) == ERROR);
}

void test1_space_set_link_south() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_link_south(s, 4) == OK);
}

void test2_space_set_link_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_link_south(s, 4) == ERROR);
}

void test1_space_set_link_east() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_link_east(s, 4) == OK);
}

void test2_space_set_link_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_link_east(s, 4) == ERROR);
}

void test1_space_set_link_west() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_link_west(s, 4) == OK);
}

void test2_space_set_link_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_link_west(s, 4) == ERROR);
}

void test1_space_set_gdesc1(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_gdesc1(s, "hola") == ERROR);
}

void test2_space_set_gdesc1(){
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_gdesc1(s, "hola") == OK);
}

void test1_space_set_gdesc2(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_gdesc2(s, "hola") == ERROR);
}

void test2_space_set_gdesc2(){
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_gdesc2(s, "hola") == OK);
}

void test1_space_set_gdesc3(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_gdesc3(s, "hola") == ERROR);
}

void test2_space_set_gdesc3(){
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_gdesc3(s, "hola") == OK);
}

void test1_space_set_description(){
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_description(s, "amigo") == OK);
}

void test2_space_set_description(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_description(s, "amigo") == ERROR);
}

void test1_space_delete_object(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_delete_object(s) == ERROR);
}

void test2_space_delete_object(){
  Space *s = NULL;
  s = space_create(1);
  space_add_object(s,2);
  PRINT_TEST_RESULT(space_delete_object(s) == OK);
}

void test1_space_add_object(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_object(s,2) == ERROR);
}

void test2_space_add_object(){
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_add_object(s,2) == OK);
}

void test1_space_get_objects(){
  Space *s = NULL;
  s = space_create(1);
  space_add_object(s,2);
  PRINT_TEST_RESULT(space_get_objects(s) != NULL);
}

void test2_space_get_objects(){
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_objects(s) != NULL);
}

void test1_space_check_in_space(){
  Space *s = NULL;
  s = space_create(1);
  space_add_object(s,1);
  PRINT_TEST_RESULT(object_check_in_space(s,1) == TRUE);
}

void test2_space_check_in_space(){
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(object_check_in_space(s,1) == FALSE);
}

void test1_space_get_name() {
    Space *s;
    s = space_create(1);
    space_set_name(s, "adios");
    PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
}

void test2_space_get_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_get_link_north() {
    Space *s;
    s = space_create(5);
    space_set_link_north(s, 4);
    PRINT_TEST_RESULT(space_get_link_north(s) == 4);
}

void test2_space_get_link_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_link_north(s) == NO_ID);
}

void test1_space_get_link_south() {
    Space *s;
    s = space_create(5);
    space_set_link_south(s, 2);
    PRINT_TEST_RESULT(space_get_link_south(s) == 2);
}

void test2_space_get_link_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_link_south(s) == NO_ID);
}

void test1_space_get_link_east() {
    Space *s;
    s = space_create(5);
    space_set_link_east(s, 1);
    PRINT_TEST_RESULT(space_get_link_east(s) == 1);
}

void test2_space_get_link_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_link_east(s) == NO_ID);
}

void test1_space_get_link_west() {
    Space *s;
    s = space_create(5);
    space_set_link_west(s, 6);
    PRINT_TEST_RESULT(space_get_link_west(s) == 6);
}

void test2_space_get_link_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_link_west(s) == NO_ID);
}

void test1_space_get_id() {
    Space *s;
    s = space_create(25);
    PRINT_TEST_RESULT(space_get_id(s) == 25);
}

void test2_space_get_id() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_get_gdesc1() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_gdesc1(s) == NULL);
}

void test2_space_get_gdesc1() {
    Space *s = NULL;
    s = space_create(1);
    space_set_gdesc1(s,"hola");
    PRINT_TEST_RESULT(strcmp(space_get_gdesc1(s),"hola")==0);
}

void test1_space_get_gdesc2() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_gdesc2(s) == NULL);
}

void test2_space_get_gdesc2() {
    Space *s = NULL;
    s = space_create(1);
    space_set_gdesc2(s,"hola");
    PRINT_TEST_RESULT(strcmp(space_get_gdesc2(s),"hola")==0);
}

void test1_space_get_gdesc3() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_gdesc2(s) == NULL);
}

void test2_space_get_gdesc3() {
    Space *s = NULL;
    s = space_create(1);
    space_set_gdesc3(s,"hola");
    PRINT_TEST_RESULT(strcmp(space_get_gdesc3(s),"hola")==0);
}

void test1_space_get_description(){
    Space *s = NULL;
    s = space_create(1);
    space_set_description(s,"hola");
    PRINT_TEST_RESULT(strcmp(space_get_description(s),"hola")==0);
}

void test2_space_get_description(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_description(s)==NULL);
}
