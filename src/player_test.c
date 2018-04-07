/**
 * @brief It tests player module
 *
 * @file player_test.c
 * @author Profesores Pprog
 * @version 2.0
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "player_test.h"
#include "test.h"

#define MAX_TESTS 24



void test1_player_create() {
  int result = player_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_player_create() {
    Player *s;
    s = player_create(4);
    PRINT_TEST_RESULT(player_get_id(s) == 4);
}

void test1_player_set_name() {
    Player *s;
    s = player_create(5);
    PRINT_TEST_RESULT(player_set_name(s, "hola") == OK);
}

void test2_player_set_name() {
    Player *s = NULL;
    PRINT_TEST_RESULT(player_set_name(s, "hola") == ERROR);
}

void test3_player_set_name() {
    Player *s;
    s = player_create(5);
    PRINT_TEST_RESULT(player_set_name(s, NULL) == ERROR);
}

void test1_player_set_location() {
    Player *s;
    s = player_create(5);
    PRINT_TEST_RESULT(player_set_location(s, 4) == OK);
}

void test2_player_set_location() {
    Player *s = NULL;
    PRINT_TEST_RESULT(player_set_location(s, 4) == ERROR);
}

void test1_player_get_name() {
    Player *s;
    s = player_create(1);
    player_set_name(s,"ok");
    PRINT_TEST_RESULT(strcmp(player_get_name(s),"ok")==0);
}

void test2_player_get_name() {
    Player *s = NULL;
    s = player_create(25);
    PRINT_TEST_RESULT(strcmp(player_get_name(s),"error")!=0);
}

void test1_player_get_inventory_items() {
    Player *s;
    s = player_create(25);
    player_add_inventory_item(s,1);
    PRINT_TEST_RESULT(player_get_inventory_items(s) != NULL);
}

void test2_player_get_inventory_items() {
    Player *s = NULL;
    PRINT_TEST_RESULT(player_get_inventory_items(s) == NULL);
}

void test1_player_get_location() {
    Player *s;
    s = player_create(1);
    player_set_location(s,8);
    PRINT_TEST_RESULT(player_get_location(s) == 8);
}

void test2_player_get_location() {
    Player *s;
    s = player_create(1);
    player_set_location(s,2);
    PRINT_TEST_RESULT(player_get_location(s) != NO_ID);
}

void test1_player_get_id() {
    Player *s;
    s = player_create(25);
    PRINT_TEST_RESULT(player_get_id(s) == 25);
}

void test2_player_get_id() {
    Player *s = NULL;
    PRINT_TEST_RESULT(player_get_id(s) == NO_ID);
}

void test1_player_delete_inventory_item_by_id(){
  Player *s;
  s = player_create(25);
  player_add_inventory_item(s,5);
  PRINT_TEST_RESULT(player_delete_inventory_item_by_id(s,5) == OK);
}

void test2_player_delete_inventory_item_by_id(){
  Player *s;
  s = player_create(25);
  PRINT_TEST_RESULT(player_delete_inventory_item_by_id(s,5) == ERROR);
}

void test1_player_delete_a_inventory_item() {
    Player *s;
    s = player_create(25);
    player_add_inventory_item(s,1);
    PRINT_TEST_RESULT(player_delete_a_inventory_item(s)  == OK);
}

void test2_player_delete_a_inventory_item() {
    Player *s;
    s = player_create(25);
    PRINT_TEST_RESULT(player_delete_a_inventory_item(s)  == ERROR);
}

void test1_player_add_inventory_item() {
    Player *s;
    s = player_create(5);
    PRINT_TEST_RESULT(player_add_inventory_item(s,56)  == OK);
}

void test2_player_add_inventory_item() {
    Player *s;
    PRINT_TEST_RESULT(player_add_inventory_item(s,56)  == OK);
}

void test1_player_ask_inventory_item() {
    Player *s;
    s = player_create(5);
    PRINT_TEST_RESULT(player_ask_inventory_item(s,56)  == FALSE);
}

void test2_player_ask_inventory_item() {
    Player *s;
    s = player_create(5);
    player_add_inventory_item(s,2);
    PRINT_TEST_RESULT(player_ask_inventory_item(s,2)  == TRUE);
}

void test1_player_print() {
    Player *s;
    s = player_create(25);
    PRINT_TEST_RESULT(player_print(s)  == OK);
}




/**
 * @brief Funcion principal de pruebas para el modulo Player.
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
        printf("Running all test for module Player:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_player_create();
    if (all || test == 2) test2_player_create();
    if (all || test == 3) test1_player_set_name();
    if (all || test == 4) test2_player_set_name();
    if (all || test == 5) test3_player_set_name();
    if (all || test == 6) test1_player_set_location();
    if (all || test == 7) test2_player_set_location();
    if (all || test == 8) test1_player_get_name();
    if (all || test == 9) test2_player_get_name();
    if (all || test == 10) test1_player_get_inventory_items();
    if (all || test == 11) test2_player_get_inventory_items();
    if (all || test == 12) test1_player_get_location();
    if (all || test == 13) test2_player_get_location();
    if (all || test == 14) test1_player_get_id();
    if (all || test == 15) test2_player_get_id();
    if (all || test == 16) test1_player_delete_inventory_item_by_id();
    if (all || test == 17) test2_player_delete_inventory_item_by_id();
    if (all || test == 18) test1_player_delete_a_inventory_item();
    if (all || test == 19) test2_player_delete_a_inventory_item();
    if (all || test == 20) test1_player_add_inventory_item();
    if (all || test == 21) test2_player_add_inventory_item();
    if (all || test == 22) test1_player_ask_inventory_item();
    if (all || test == 23) test2_player_ask_inventory_item();
    if (all || test == 24) test1_player_print();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}
