/**
 * @brief It declares the tests for the link module
 *
 * @file link_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Prueba la función de creación de un objeto
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al objeto creado
 */

/**
 * @test Prueba la función de creación de un objeto
 * @pre Un identificador como parámetro
 * @post El identificador del objeto es el introducido
 */

/**
 * @test Prueba la función para establecer el nombre de un objeto
 * @pre Nombre que establecer al objeto
 * @post La salida debe ser OK
 */

/**
 * @test Prueba la función para establecer el nombre de un objeto
 * @pre El objeto al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */

/**
 * @test Prueba la función para establecer el nombre de un objeto
 * @pre El objeto es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test1_link_create();
void test2_link_create();
void test3_link_create();
void test1_link_set_name();
void test2_link_set_name();
void test1_link_set_id();
void test2_link_set_id();
void test1_link_set_bool_state();
void test2_link_set_bool_state();
void test1_link_set_id_space1();
void test2_link_set_id_space1();
void test1_link_set_id_space2();
void test2_link_set_id_space2();
void test1_link_get_name();
void test2_link_get_name();
void test1_link_get_id();
void test2_link_get_id();
void test1_link_get_bool_state();
void test2_link_get_bool_state();
void test1_link_get_id_space1();
void test2_link_get_id_space1();
void test1_link_get_id_space2();
void test2_link_get_id_space2();

#endif
