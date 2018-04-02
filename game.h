/**
*@brief Define la interfaz del juego
*
*
*@file game.h
*@author FJNR & AMH & CMF & MLR
*@version 1.0
*@date 03/02/2018
*@copyright GNU Public License
*/

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "player.h"
#include "object.h"
#include "dice.h"
#include "link.h"

typedef struct _Game Game;

/**
 * @author Francisco Nanclares
 * @brief Inicialización de la estructura Game
 * @param game, puntero a puntero de game.
 * @return status, OK O ERROR
 */
STATUS game_create(Game** game);



/**
 * @author Francisco Nanclares
 * @brief Crea el juego, carga las casillas (data.dat) y ponen el objeto y jugador
    en la posición primera.
 * @param game, puntero a estructura Game (dirección)
 * @param filename, fichero de casillas (data.dat)
 * @return status, OK O ERROR
 */
STATUS game_create_from_file(Game** game, char* filename);



/**
 * @author Alejandro Martin
 * @brief Actualizacion de los comandos (muestra el último).
 * @param game, puntero a la estructura Game
 * @param cmd, enumeración (identificador de cada comando)
 * @return status, OK O ERROR
 */
STATUS game_update(Game* game, T_Command cmd,char *param,char *movement,FILE *pf);



/**
 * @author Alejandro Martin
 * @brief Elimina las casillas creadas en la función anterior
 * @param game, puntero a estructura Game (dirección)
 * @return status, OK O ERROR
 */
STATUS game_destroy(Game* game);


/**
 * @author Francisco Nanclares
 * @brief funcionalidad de modificar la localizacion del jugador mediante el id
 * @param game, puntero a Game (dirección)
 * @param id, Entero de tipo Id (identificador)
 * @return status, OK O ERROR
 */
STATUS game_set_player_location(Game* game, Id id);



/**
 * @author Francisco Nanclares
 * @brief funcionalidad de modificar la localizacion del objeto mediante el id
 * @param game,puntero a la estructura Game
 * @param id_espacio, campo de la estructura Id
 * @param object, puntero a la estructura de object
 * @return status, OK O ERROR
 */
 /*acordarse de donde se encuentra la funcionalidad y donde se llama a ella  */
STATUS game_set_object_location(Game* game, Id id_espacio,Object * object);




/**
 * @author Alejandro Martin
 * @brief Posible llamada a la finalización del juego
 * @param game, puntero a la estructura Game
 * @return bool, TRUE or FALSE
 */
BOOL game_is_over(Game* game);



/**
 * @author Alejandro Martin
 * @brief Imprime la pantalla de juego
 * @param game, puntero a la estructura Game
 * @return nada, es de tipo void
 */
void game_print_screen(Game* game);



/**
 * @author Francisco Nanclares
 * @brief Imprime la "info" de todas las casillas ,y la posición del jugador y
    de los objetos.
 * @param game, puntero a la estructura Game
 * @return nada
 */
void game_print_data(Game* game);



/**
 * @author Francisco Nanclares
 * @brief Retorna la casilla (asociándola con una posición predeterminada)
    y con el id (param)
 * @param game, puntero a estructura,(dirección)
 * @param id, Entero (identificador)
 * @return NULL (si el id esta corrupto, o al final de la función),
    y el array "spaces", de la estructura, si coincide con el id pasado como argumento
 */
Space* game_get_space(Game* game, Id id);



/**
 * @author Alejandro Martin
 * @brief Retorna el objeto (asociándola con una posición predeterminada)
    y con el id (param)
 * @param game, puntero a estructura,(dirección)
 * @param id, Entero (identificador)
 * @return NULL (si el id esta corrupto, o al final de la función),
    y el array "objects", de la estructura, si coincide con el id pasado como argumento
 */
Object* game_get_object(Game* game, Id id);




/*
 * @author Alejandro Martin
 * @brief Retorna el link asociandolo con un identificador
 * @param game, puntero a estructura,(dirección)
 * @param id, Entero (identificador)
 * @return NULL (si el id esta corrupto, o al final de la función),
    y el array "links", de la estructura, si coincide con el id pasado como argumento
 */
Link* game_get_link (Game* game, Id id);


/**
 * @author Alejandro Martin
 * @brief Esta funcion,
 * @param game, puntero a estructura,(dirección)
 * @param name, puntero a char
 * @return
 */
Id game_object_get_id_by_name(Game *game , char *name);


/**
 * @author Alejandro Martin
 * @brief Esta funcion,
 * @param game, puntero a estructura,(dirección)
 * @param name, puntero a char
 * @return
 */
Id game_space_get_id_by_name (Game *game , char *name);



/**
 * @author Alejandro Martin
 * @brief Devuelve la posicion del jugador (estructura game)
 * @param game, puntero a la estructura Game
 * @return la posición del jugador, modificada de la estructura
 */
Id game_get_player_location(Game* game);



/**
 * @author Francisco Nanclares
 * @brief Devuelve la posicion del objeto (estructura game)
 * @param game, puntero a la estructura Game
 * @return la posición del objeto, modificada de la estructura
 *//*  return location(id) o NO_ID (id)
*/
Id game_get_object_location(Game* game,Object * object);



/**
 * @author Alejandro Martin
 * @brief Devuelve el último comando que se ha introducido.
 * @param game, puntero a la estructura Game
 * @return cmd, el último comando.
 */
T_Command game_get_last_command(Game* game);



/**
 * @author Francisco Nanclares
 * @brief Crea un objeto , comprobando el array de objetos ,lo recorre Entero
    hasta que se acaba y anade el objeto pasado por parametro
 * @param game, puntero a estructura Game (dirección)
 * @param object , puntero a estructura Object
 * @return status, OK O ERROR
 */
STATUS game_add_object (Game * game , Object* object);



/**
 * @author Francisco Nanclares
 * @brief Crea un link , y anade el link pasado por parametro
 * @param game, puntero a estructura Game (dirección)
 * @param link , puntero a estructura Link
 * @return status, OK O ERROR
 */
STATUS game_add_link (Game * game , Link *link);



/**
 * @author Francisco Nanclares
 * @brief Obtiene los id, los campara, y nos dice si hay objeto
 * @param game, puntero a la estructura Game
 * @param object, puntero a object
 * @return bool, TRUE or FALSE
 */
BOOL game_get_object_player(Game* game , Object* object);



/**
 * @author Alejandro Martin
 * @brief Crea una casilla una vez comprobado el array (hasta que apunte a NULL)
    el espacio que se añade es el parámetro
 * @param game, puntero a estructura Game (dirección)
 * @param space , puntero a estructura Space (dirección)
 * @return status, OK O ERROR
 */
STATUS game_add_space(Game* game, Space* space);



/**
 * @author Francisco Nanclares
 * @brief modificamos un string (parametro) descripcion grafica
 * @param game, puntero a estructura Game (dirección)
 * @param param, de tipo puntero a char (string) (el parametro)
 * @return nada, es de tipo void
 */
void game_set_parametro (Game * game , char *param);



/**
 * @author Francisco Nanclares
 * @brief cogemos el parametro
 * @param game, puntero a estructura Game (dirección)
 * @return game->param, es de tipo puntero a char (string)
 */
char* game_get_parametro (Game *game);



/**
 * @author Francisco Nanclares
 * @brief modificamos el movimiento
 * @param game, puntero a estructura Game (dirección)
 * @param movement, de tipo puntero a char (string) (el movimiento)
 * @return nada, es de tipo void
 */
void game_set_movement (Game * game , char *movement);


/**
 * @author Francisco Nanclares
 * @brief cogemos el movimiento
 * @param game, puntero a estructura Game (dirección)
 * @return game->movement, es de tipo puntero a char (string)
 */
char* game_get_movement (Game *game);



/**
 * @author Francisco Nanclares
 * @brief Hace flag del cmd
 * @param game, puntero a la estructura Game
 * @return flag_command, que es la flag de la estructura game
 */
STATUS game_get_last_command_flag(Game *game);




/**
 * @author Francisco Nanclares
 * @brief Obtiene un dado
 * @param game, puntero a la estructura Game
 * @return dice , que es el dice de la estructura de game
 */
Dice* game_get_dice(Game *game);


/**
 * @author Francisco Nanclares
 * @brief Obtiene la descripcion de un objeto
 * @param game, puntero a la estructura Game
 * @return game->description_object (string)
 */
char* game_get_object_description(Game *game);



/**
 * @author Francisco Nanclares
 * @brief Obtiene la descripcion de un espacio
 * @param game, puntero a la estructura Game
 * @return game->description_space (string)
 */
char* game_get_space_description(Game *game);


#endif
