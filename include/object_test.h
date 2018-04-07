/**
 * @brief It declares the tests for the object module
 *
 * @file object_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

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
void test1_object_create();
void test2_object_create();
void test1_object_set_name();
void test2_object_set_name();
void test3_object_set_name();
void test1_object_set_location();
void test2_object_set_location();
void test1_object_set_description();
void test2_object_set_description();
void test1_object_get_name();
void test2_object_get_name();
void test1_object_get_location();
void test2_object_get_location();
void test1_object_get_id();
void test2_object_get_id();
void test1_object_get_description();
void test2_object_get_description();

#endif
