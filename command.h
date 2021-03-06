/**
*@brief Muestra la funcionalidad de la estructura de datos
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
    FOLLOWING, /*etc*/
    PREVIOUS,
    LEFT,
    RIGHT,
    GET,
    DROP,
    DICE_ROLL
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
