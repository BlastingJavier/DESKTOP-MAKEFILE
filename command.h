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
    UNKNOWN, /*0*/
    EXIT, /*1*/
    SOUTH, /*2*/
    NORTH, /*3*/
    WEST,/*4*/
    EAST,/*5*/
    GET,/*6*/
    DROP,/*7*/
    DICE_ROLL,/*8*/
    MOVEMENT,/*9*/
    CHECK/*10*/
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
