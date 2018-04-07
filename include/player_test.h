/**
 * @brief It declares the tests for the player module
 *
 * @file player_test.h
 * @author FNR & CMF & AMH & ML
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
 * @test Prueba la función de creación de un player
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al player creado
 */
void test1_player_create();

/**
 * @test Prueba la función de creación de un player
 * @pre Un identificador como parámetro
 * @post El identificador del player es el introducido
 */
void test2_player_create();

/**
 * @test Prueba la función para establecer el nombre de un player
 * @pre Nombre que establecer al player
 * @post La salida debe ser OK
 */
void test1_player_set_name();

/**
 * @test Prueba la función para establecer el nombre de un player
 * @pre El player al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_player_set_name();

/**
 * @test Prueba la función para establecer el nombre de un player
 * @pre El player es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test1_player_create();
void test2_player_create();
void test1_player_set_name();
void test2_player_set_name();
void test3_player_set_name();
void test1_player_set_location();
void test2_player_set_location();
void test1_player_get_name();
void test2_player_get_name();
void test1_player_get_inventory_items();
void test2_player_get_inventory_items();
void test1_player_get_location();
void test2_player_get_location();
void test1_player_get_id();
void test2_player_get_id();
void test1_player_delete_inventory_item_by_id();
void test2_player_delete_inventory_item_by_id();
void test1_player_delete_a_inventory_item();
void test2_player_delete_a_inventory_item();
void test1_player_add_inventory_item();
void test2_player_add_inventory_item();
void test1_player_ask_inventory_item();
void test2_player_ask_inventory_item();
void test1_player_print();

#endif
