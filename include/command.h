/**
*@brief Muestra la funcionalidad de la estructura de datos (interfaz)
*
*@file command.h
*@author FJNR & AMH & CMF & MLR
*@version 1.0
*@date 01/02/2018
*@copyright GNU Public License
*/

#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief Enumeración de cada comando posible
*/
typedef enum enum_Command {
    NO_CMD = -1,
    UNKNOWN, /*!<Num:0*/
    EXIT, /*!<Num:1*/
    SOUTH, /*!<Num:2*/
    NORTH, /*!<Num:3*/
    WEST,/*!<Num:4*/
    EAST,/*!<Num:5*/
    GET,/*!<Num:6*/
    DROP,/*!<Num:7*/
    DICE_ROLL,/*!<Num:8*/
    MOVEMENT,/*!<Num:9*/
    CHECK/*!<Num:10*/
} T_Command;




/**
* @author Alejandro Martin
* @brief Implementa los comandos, recogiendo el "input" ,
   transformándolo en un valor numérico de T_command;
* @param No param.
* @return cmd (campo de estructura T_command)
*/
T_Command get_user_input();

#endif
